#include "Cone.h"

namespace omgl{

	Cone::Cone():GLTriangles(){

		addChild(&m_Back);
		setDivNum(16);
	}
	void Cone::setDivNum(int n){
		ASSERT(n>=3);

		m_Back.setDivNum(n);

		m_Vertices.clear();
		m_Indices.clear();

		m_Vertices.resize(3*(1+n));
		m_Indices.resize(3*n);

		m_Vertices[0]=0.f;
		m_Vertices[1]=0.f;
		m_Vertices[2]=1.f;

		float angle = M_2PI / static_cast<float>(n);
		for(int i=0;i<n;i++){
			m_Vertices[3*(i+1)+0] = 0.5f * glm::cos(angle*i);
			m_Vertices[3*(i+1)+1] = 0.5f * glm::sin(angle*i);
			m_Vertices[3*(i+1)+2] = 0.f;
		}

		for(int i=0;i<n;i++){
			m_Indices[3*i + 0] = 0;
			m_Indices[3*i + 1] = (i+1)%n + 1;
			m_Indices[3*i + 2] = (i+0)%n + 1;
		}
	}

	void Cone::setColorAll(const Color &c){
		setColor(c);
		m_Back.setColor(c);
	}

}