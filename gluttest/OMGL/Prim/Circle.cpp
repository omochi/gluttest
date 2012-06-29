#include "Circle.h"

namespace omgl{
	Circle::Circle():GLTriangles(){
		setDivNum(16);
	}
	void Circle::setDivNum(int n){
		ASSERT(n>=3);
		m_Vertices.clear();
		m_Indices.clear();


		addVertex(0.f,0.f,0.f).setNormal(0,0,1);
		
		for(int i=0;i<n;i++){
			float angle = M_2PI / static_cast<float>(n);
			addVertex(	0.5f * glm::cos(angle*i),
						0.5f * glm::sin(angle*i),
						0.0f).
						setNormal(0,0,1);
		}
		for(int i=0;i<n;i++){
			addIndex(0,(i+0)%n + 1,(i+1)%n + 1);
		}
	}
}