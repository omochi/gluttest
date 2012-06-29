#include "Sphere.h"

namespace omgl{
	Sphere::Sphere():GLTriangles(){
		setDivNum(10,10);
	}
	void Sphere::setDivNum(int latN,int lngN){
		ASSERT(latN>=2);
		ASSERT(lngN>=3);
		m_Vertices.clear();
		m_Indices.clear();

		int yN = (latN+1);
		int xN = lngN;
		
		float angX = M_2PI / lngN;
		float angY = M_PI / latN;

		for(int ix = 0; ix < xN;ix++){
			float lng = angX * ix;
			for(int iy = 0;iy < yN; iy++){
				float lat = angY * iy;
				vec3 p(
					glm::sin(lng) * glm::sin(lat),
					glm::cos(lat),
					glm::cos(lng) * glm::sin(lat)
					);
				
				addVertex(0.5f*p).setNormal(p);
			}
		}

		for(int ix = 0;ix <lngN;ix++){
			int ixLeft = ix*yN;
			int ixRight = (ix+1)%lngN * yN;
			for(int iy=0;iy<latN;iy++){
				int iyUp = iy;
				int iyDown = iy+1;
				addIndex(
					ixRight+iyUp,
					ixLeft+iyUp,
					ixLeft+iyDown
					);
				addIndex(
					ixLeft+iyDown,
					ixRight+iyDown,
					ixRight+iyUp
					);
			}
		}

	}
}