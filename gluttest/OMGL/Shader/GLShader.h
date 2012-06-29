#pragma once

#include <OMBase/OMBase.h>

namespace omgl{
	class GLShader{
	public:
		GLuint m_Id;
		GLenum m_Type;
		std::string m_Path;

		GLShader():m_Id(0){}

		bool create(GLenum type);
		void release();
		bool compile(std::string path);		
		std::string getLog();

		bool load(GLenum type,std::string path);
	};
}