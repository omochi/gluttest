#include "GLShader.h"

namespace omgl{
	bool GLShader::create(GLenum type){
		if(m_Id!=0)return false;
		m_Type = type;
		m_Id = glCreateShader(type);
		if(m_Id == 0)return false;
		return true;
	}

	bool GLShader::compile(std::string path){
		m_Path = path;
		base::FileReader fr;
		std::vector<char> source;
		if(!fr.read(source,path))return false;
		source.push_back('\0');

		const GLchar *pSource = &source[0];

		glShaderSource(m_Id,1,&pSource,NULL);
		glCompileShader(m_Id);

		GLint status;
		glGetShaderiv(m_Id,GL_COMPILE_STATUS,&status);
		if(status==0){
			fprintf(stderr,"compile error : %s\n%s",path.c_str(),getLog().c_str());
			return false;
		}
		return true;
	}

	void GLShader::release(){
		if(m_Id!=0){
			glDeleteShader(m_Id);
		}
		m_Id = 0;
	}

	std::string GLShader::getLog(){
		std::string log;
		GLint len;
		if(m_Id!=0){
			glGetShaderiv(m_Id,GL_INFO_LOG_LENGTH,&len);
			if(len>0){
				std::string buf;
				buf.resize(len);
				glGetShaderInfoLog(m_Id,len,&len,&buf[0]);
				log.append(buf);
			}
		}
		return log;
	}

	bool GLShader::load(GLenum type,std::string path){
		if(!create(type))return false;

		if(!compile(path)){
			release();
			return false;
		}

		return true;
	}
}