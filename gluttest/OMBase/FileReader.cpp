#include "FileReader.h"

namespace base{
	bool FileReader::read(std::vector<char> &dst,const std::string &path)const{
		dst.clear();
		FILE *fp = fopen(path.c_str(),"rb");
		if(fp==NULL)return false;
		while(!feof(fp)){
			char buf[1000];
			int len = fread(&buf,sizeof(char),ARRAY_SIZE(buf),fp);
			if(ferror(fp)){
				fclose(fp);
				return false;
			}
			if(len>0){
				std::vector<char> piece(buf,&buf[len]);
				dst.insert(dst.end(),piece.begin(),piece.end());
			}

		}
		return true;
	}
}