#include "Square.h"	

namespace omgl{
	Square::Square():GLTriangles(){
		m_Vertices.clear();
		m_Indices.clear();


		addVertex(0.5f,0.5f,0.0f).
			setNormal(0.f,0.f,1.f);

		addVertex(-0.5f,0.5f,0.0f).
			setNormal(0.f,0.f,1.f);

		addVertex(-0.5f,-0.5f,0.0f).
			setNormal(0.f,0.f,1.f);

		addVertex(0.5f,-0.5f,0.0f).
			setNormal(0.f,0.f,1.f);

		addIndex(0,1,2);
		addIndex(2,3,0);
	}
}