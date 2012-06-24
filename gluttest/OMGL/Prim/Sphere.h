#pragma once
#include "GLTriangles.h"
namespace omgl{
	class Sphere : public GLTriangles{
	private:
	public:
		Sphere();
		void setDivNum(int latN,int lngN);
	};
}