#pragma once
#include "common.h"

namespace omgl{
	class GLBufferObject{
	public:
		GLuint m_Id;
		GLBufferObject():m_Id(0){}
		bool create();
		void release();
		bool bind(GLenum type) const;

		template <class T>
		bool setData(GLenum type,const std::vector<T> &data,GLenum usage){
			if(!bind(type))return false;
			glBufferData(type,sizeof(T) * data.size(),&data[0],usage);
			if(glGetError()!=GL_NO_ERROR)return false;
			return true;
		}

		template <class T>
		bool load(GLenum type,const std::vector<T> &data,GLenum usage){
			if(!create())return false;
			if(!setData(type,data,usage))return false;
			return true;
		}
	};
}