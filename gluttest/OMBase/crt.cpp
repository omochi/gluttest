#include "crt.h"
namespace base{
	FILE *fopen(const char *path,const char *mode){
		FILE *fp = NULL;
#ifdef _WIN32
		if(fopen_s(&fp,path,mode)!=0){
			fp=NULL;
		}
#else
		fp = ::fopen(path,mode);
#endif
		return fp;
	}

	int snprintf(char *str,size_t len,const char *format,...){
		int ret = 0;
		va_list args;
		va_start(args,format);

#ifdef _WIN32
		ret = vsnprintf_s(str,len,_TRUNCATE,format,args);
#else
		ret = vsnprintf(str,len,format,args);
#endif
		va_end(args);

		return ret;
	}
}

