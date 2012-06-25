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
}