#pragma once

#include "GLTriangles.h"

namespace omgl{
	class Circle : public GLTriangles{
	private:
		int m_DivNum;
	public:
		Circle();
		void setDivNum(int n);
	};
}