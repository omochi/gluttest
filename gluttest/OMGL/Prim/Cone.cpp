#include "Cone.h"

namespace omgl{

	Cone::Cone():GLTriangles(){
		m_Back.setRotEular(M_PI,0,0);

		addChild(&m_Back);
		setDivNum(16);
	}
	void Cone::setDivNum(int n){
		ASSERT(n>=3);
		float angle = M_2PI / static_cast<float>(n);

		m_Back.setDivNum(n);


		m_Vertices.clear();
		m_Indices.clear();

		
		for(int i=0;i<n;i++){
			///vec3 normal(glm::cos(angle*i),glm::sin(angle*i),0.5f);

			//normal = glm::normalize(normal);

			addVertex(0.f,0.f,1.f).
				//setNormal(glm::cos(angle*(i+0.5f)),glm::sin(angle*(i+0.5f)),0.5f);
				setNormal(0,0,0.f);
			addVertex(
				0.5f * glm::cos(angle*i),
				0.5f * glm::sin(angle*i),
				0.f).setNormal(
				glm::cos(angle*i),
				glm::sin(angle*i),
				0.5f);
		}

		for(int i=0;i<n;i++){
			addIndex(2*i,2*i+1,2*((i+1)%n)+1);
		}

		

	}

	void Cone::setColorAll(const Color &c){
		setColor(c);
		m_Back.setColor(c);
	}

}