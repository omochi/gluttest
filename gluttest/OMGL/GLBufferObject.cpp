#include "GLBufferObject.h"

namespace omgl{
	bool GLBufferObject::create(GLenum type){
		if(m_Id!=0)return false;
		glGenBuffers(1,&m_Id);
		m_Type = type;
		if(glGetError()!=GL_NO_ERROR)return false;
		return true;
	}
	void GLBufferObject::release(){
		if(m_Id!=0){
			glDeleteBuffers(1,&m_Id);
			m_Id = 0;
		}
	}
	bool GLBufferObject::bind() const{
		return bind(m_Type);
	}
	bool GLBufferObject::unbind() const{
		return unbind(m_Type);
	}

	bool GLBufferObject::bind(GLenum type) const{
		if(m_Id==0)return false;
		glBindBuffer(type,m_Id);
		GLenum er = glGetError();
		if(er!=GL_NO_ERROR)return false;
		return true;
	}
	bool GLBufferObject::unbind(GLenum type)const{
		glBindBuffer(type,0);
		return glGetError()==GL_NO_ERROR;
	}
}