#include "GLProgram.h"

namespace omgl{
	bool GLProgram::create(){
		m_Id = glCreateProgram();
		if(m_Id==0)return false;
		return true;
	}
	void GLProgram::release(){
		m_Vsh.release();
		m_Fsh.release();
		if(m_Id!=0){
			glDeleteProgram(m_Id);
			m_Id=0;
		}
	}
	void GLProgram::attachShader(const GLShader &sh){
		if(m_Id!=0 && sh.m_Id!=0){
			glAttachShader(m_Id,sh.m_Id);
		}
	}
	void GLProgram::detachShader(const GLShader &sh){
		if(m_Id!=0 && sh.m_Id!=0){
			glDetachShader(m_Id,sh.m_Id);
		}
	}
	bool GLProgram::link(){
		glLinkProgram(m_Id);

		GLint status;
		glGetProgramiv(m_Id,GL_LINK_STATUS,&status);
		if(status==0){
			fprintf(stderr,"link error : %s,%s\n%s",
				m_Vsh.m_Path.c_str(),m_Fsh.m_Path.c_str(),
				getLog().c_str());
			return false;
		}
		return true;
	}

	std::string GLProgram::getLog(){
		std::string log;
		GLint len;
		if(m_Id!=0){
			glGetShaderiv(m_Id,GL_INFO_LOG_LENGTH,&len);
			if(len>0){
				std::string buf;
				buf.resize(len);
				glGetProgramInfoLog(m_Id,len,&len,&buf[0]);
				log.append(buf);
			}
		}
		return log;
	}

	void GLProgram::bindAttribLocation(GLuint index,const GLchar *name){
		if(m_Id!=0){
			glBindAttribLocation(m_Id,index,name);
		}
	}
	GLint GLProgram::getUniformLocation(const GLchar *name){
		if(m_Id!=0){
			return glGetUniformLocation(m_Id,name);
		}else{
			return -1;
		}
	}

	void GLProgram::use(){
		glUseProgram(m_Id);
	}

	bool GLProgram::load(){
		return load(getVshPath(),getFshPath());
	}

	bool GLProgram::load(std::string vshPath,std::string fshPath){
		if(!create())return false;

		if(!m_Vsh.load(GL_VERTEX_SHADER,vshPath)){
			release();
			return false;
		}
		if(!m_Fsh.load(GL_FRAGMENT_SHADER,fshPath)){
			release();
			return false;
		}

		attachShader(m_Vsh);
		attachShader(m_Fsh);
		
		onPreLink();
		
		if(!link()){
			release();
			return false;
		}

		onPostLink();

		detachShader(m_Vsh);
		detachShader(m_Fsh);
		m_Vsh.release();		
		m_Fsh.release();

		return true;

	}
}