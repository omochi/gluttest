#pragma once

#include "common.h"


#define ASSERT(exp) {\
	if(!(exp)){\
		char buf[1000];\
		base::snprintf(buf,sizeof(buf),"assert:%s:%s:%s:%d",#exp,__FILE__,__FUNCTION__,__LINE__);\
		throw std::exception(buf);\
	}\
}


#define FAIL(msg){ \
	char buf[1000]; \
	base::snprintf(buf,sizeof(buf),"fail:%s:%s:%s:%d",msg,__FILE__,__FUNCTION__,__LINE__);\
	throw std::exception(buf);\
}

#define ARRAY_SIZE(x) (sizeof(x) / sizeof( (x)[0]) )

#define SAFE_DELETE(p) {\
	ASSERT((p)!=NULL);\
	delete (p);\
	p=NULL;\
}

#define OFFSET(o) ((char *)NULL+(o))

template<class T>
T cycleClamp(T x,const T &min,const T &max){
	while(x<min)x+=(max-min);
	while(x>max)x-=(max-min);
	return x;
}
