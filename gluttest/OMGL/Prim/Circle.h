#pragma once

#include "GLTriangles.h"
#include <gl/glut.h>

namespace omgl{
	class Circle : public GLTriangles{
	private:
		int m_DivNum;
	public:
		Circle();
		void setDivNum(int n);
	};
}