#pragma once

#include "common.h"

#define ASSERT(exp) {\
	if(!(exp)){\
		fprintf(stderr,"assert error:%s:%s,%s,%d",#exp,__FILE__,__FUNCTION__,__LINE__);\
		throw std::exception();\
	}\
}

#define FAIL(msg){\
	fprintf(stderr,"fail:%s:%s,%s,%d",msg,__FILE__,__FUNCTION__,__LINE__);\
	throw std::exception();\
}

#define ARRAY_SIZE(x) (sizeof(x) / sizeof( (x)[0]) )

#define SAFE_DELETE(p) {\
	ASSERT((p)!=NULL);\
	delete (p);\
	p=NULL;\
}

template<class T>
T cycleClamp(T x,const T &min,const T &max){
	while(x<min)x+=(max-min);
	while(x>max)x-=(max-min);
	return x;
}

/*
#define CYCLE_CLAMP(x,min,max) {\
	while((x)<(min))x+=(max)-(min);\
	while((x)>(max))x-=(max)-(min);\
}
*/