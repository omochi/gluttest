#pragma once

#include "GLTriangles.h"
#include "Circle.h"

namespace omgl{
	class Cylinder : public GLTriangles{
	private:
		int m_DivNum;
	public:
		Circle m_Front;
		Circle m_Back;

		Cylinder();
		void setDivNum(int n);

		void setColorAll(const Color &c);
	};
}