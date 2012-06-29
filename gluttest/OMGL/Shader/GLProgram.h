#pragma once
#include <OMBase/OMBase.h>
#include "../common.h"
#include "GLShader.h"
namespace omgl{
	class GLProgram{
	public:
		GLuint m_Id;

		GLShader m_Vsh;
		GLShader m_Fsh;

		GLProgram():m_Id(0){}

		bool create();
		void release();
		void attachShader(const GLShader &sh);
		void detachShader(const GLShader &sh);

		bool link();
		std::string getLog();
		bool load();
		bool load(std::string vshPath,std::string fshPath);

		void bindAttrib(GLuint index,const GLchar *name);
		GLint getUniform(const GLchar *name);

		void use();
		
	protected:
		virtual std::string getVshPath(){ return ""; };
		virtual std::string getFshPath(){ return ""; };
		virtual void onPreLink(){};
		virtual void onPostLink(){};
	};
}