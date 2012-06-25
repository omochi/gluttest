#include "Circle.h"

namespace omgl{
	Circle::Circle():GLTriangles(){
		setDivNum(16);
	}
	void Circle::setDivNum(int n){
		ASSERT(n>=3);
		m_Vertices.clear();
		m_Indices.clear();

		m_Vertices.resize(3*(1+n));
		m_Indices.resize(3*n);

		m_Vertices[0]=0.f;
		m_Vertices[1]=0.f;
		m_Vertices[2]=0.f;

		float angle = M_2PI / static_cast<float>(n);
		
		int idx = 3;
		for(int i=0;i<n;i++){
			m_Vertices[idx+0] = 0.5f * glm::cos(angle*i);
			m_Vertices[idx+1] = 0.5f * glm::sin(angle*i);
			m_Vertices[idx+2] = 0.f;

			idx+=3;
		}

		idx = 0;
		for(int i=0;i<n;i++){
			m_Indices[idx + 0] = 0;
			m_Indices[idx + 1] = (i+0)%n + 1;
			m_Indices[idx + 2] = (i+1)%n + 1;
			idx+=3;
		}

	}
}