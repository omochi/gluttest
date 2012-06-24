#pragma once
#include "GLTriangles.h"
#include "Circle.h"
namespace omgl{
	class Cone : public GLTriangles{
	private:
		int m_DivNum;
	public:
		Circle m_Back;
		Cone();
		void setDivNum(int n);
		void setColorAll(const Color &c);
	};
}