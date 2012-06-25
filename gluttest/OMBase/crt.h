#pragma once
#include "common.h"
namespace base{
	FILE *fopen(const char *path,const char *mode);
	int snprintf(char *str,size_t len,const char *format,...);
}