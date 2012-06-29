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

		Vertex &v = Vertex();
		
		v=addVertex(Vertex().setPos(0.f,0.f,1.f));

		float angle = M_2PI / static_cast<float>(n);
		for(int i=0;i<n;i++){
			v = addVertex(Vertex().setPos(
				0.5f * glm::cos(angle*i),
				0.5f * glm::sin(angle*i),
				0.f));
		}

		for(int i=0;i<n;i++){
			addIndex(0,(i+1)%n + 1,(i+0)%n + 1);
		}
	}

	void Cone::setColorAll(const Color &c){
		setColor(c);
		m_Back.setColor(c);
	}

}