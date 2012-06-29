#include "Square.h"	

namespace omgl{
	Square::Square():GLTriangles(){
		m_Vertices.clear();
		m_Indices.clear();

		Vertex &v = Vertex();
		
		v = addVertex(Vertex().setPos(0.5f,0.5f,0.0f));
		v.normal = vec3(0.f,1.f,0.f);

		v = addVertex(Vertex().setPos(-0.5f,0.5f,0.0f));
		v.normal = vec3(0.f,1.f,0.f);

		v = addVertex(Vertex().setPos(-0.5f,-0.5f,0.0f));
		v.normal = vec3(0.f,1.f,0.f);

		v = addVertex(Vertex().setPos(0.5f,-0.5f,0.0f));
		v.normal = vec3(0.f,1.f,0.f);

		addIndex(0,1,2);
		addIndex(2,3,0);
	}
}