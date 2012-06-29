#pragma once
#include "common.h"

namespace omgl{
	class GLBufferObject{
	public:
		GLuint m_Id;
		GLenum m_Type;
		int m_DataNum;
		GLBufferObject():m_Id(0),m_DataNum(0){}
		bool create(GLenum type);
		void release();
		
		bool bind() const;
		bool bind(GLenum type) const;
		bool unbind() const;
		bool unbind(GLenum type)const;



		template <class T>
		bool setData(const std::vector<T> &data,GLenum usage){
			if(!bind())return false;
			m_DataNum = data.size();
			glBufferData(m_Type,sizeof(T) * data.size(),&data[0],usage);
			if(glGetError()!=GL_NO_ERROR)return false;
			if(!unbind())return false;
			return true;
		}

		template <class T>
		bool load(GLenum type,const std::vector<T> &data,GLenum usage){
			if(!create(type))return false;
			if(!setData(data,usage))return false;
			return true;
		}
	};
}