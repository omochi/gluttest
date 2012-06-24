#include "Cylinder.h"

namespace omgl{
	Cylinder::Cylinder():GLTriangles(){
		m_Front.setPos(0,0,0.5);

		m_Back.setPos(0,0,-0.5);
		m_Back.setRotEular(M_PI,0,0);


		addChild(&m_Front);
		addChild(&m_Back);

		setDivNum(16);
	}
	void Cylinder::setDivNum(int n){
		ASSERT(n>=3);

		m_Front.setDivNum(n);
		m_Back.setDivNum(n);

		m_Vertices.clear();
		m_Indices.clear();

		m_Vertices.resize(3*2*n);
		m_Indices.resize(3*2*n);

		float angle = M_2PI / static_cast<float>(n);
		for(int i=0;i<n;i++){
			m_Vertices[6*(i)+0] = 0.5f * glm::cos(angle*i);
			m_Vertices[6*(i)+1] = 0.5f * glm::sin(angle*i);
			m_Vertices[6*(i)+2] = -0.5f;

			m_Vertices[6*(i)+3] = m_Vertices[6*(i)+0];
			m_Vertices[6*(i)+4] = m_Vertices[6*(i)+1];
			m_Vertices[6*(i)+5] = +0.5f;
		}

		for(int i=0;i<n;i++){
			m_Indices[6*i+0]=(i+0)%n*2+1;
			m_Indices[6*i+1]=(i+0)%n*2+0;
			m_Indices[6*i+2]=(i+1)%n*2+0;

			m_Indices[6*i+3]=(i+1)%n*2+0;
			m_Indices[6*i+4]=(i+1)%n*2+1;
			m_Indices[6*i+5]=(i+0)%n*2+1;
		}
	}
	void Cylinder::setColorAll(const Color &c){
		setColor(c);
		m_Front.setColor(c);
		m_Back.setColor(c);
	}
}