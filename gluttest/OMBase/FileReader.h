#pragma once
#include <OMBase/OMBase.h>

namespace base{
	class FileReader{
	public:
		bool read(std::vector<char> &dst,const std::string &path)const;

	};
}
