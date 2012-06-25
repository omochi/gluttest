#pragma once
//“à•”‹¤’Ê
#include <OMBase/OMBase.h>

#define ASSERT_GL() {\
	GLenum err = glGetError();\
	if(err!=GL_NO_ERROR){\
		char buf[1000];\
		base::snprintf(buf,sizeof(buf),"GL:%s",gluErrorString(err));\
		FAIL(buf);\
	}\
}