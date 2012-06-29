#include "Sphere.h"

namespace omgl{
	Sphere::Sphere():GLTriangles(){
		setDivNum(8,8);
	}
	void Sphere::setDivNum(int latN,int lngN){
		ASSERT(latN>=2);
		ASSERT(lngN>=3);
		m_Vertices.clear();
		m_Indices.clear();

		int yN = (latN-1);
		int xN = lngN;

		Vertex &v = Vertex();
		
		v = addVertex(Vertex().setPos(0,0.5f,0));
		v = addVertex(Vertex().setPos(0,-0.5f,0));

		float angX = M_2PI / lngN;
		float angY = M_PI / latN;

		for(int ix = 0; ix < xN;ix++){
			float lng = angX * ix;
			for(int iy = 0;iy < yN; iy++){
				float lat = angY * (iy+1);

				v=addVertex(Vertex().setPos(
					0.5f * glm::sin(lng) * glm::sin(lat),
					0.5f * glm::cos(lat),
					0.5f * glm::cos(lng) * glm::sin(lat)
					));

			}
		}

		for(int ix = 0;ix < lngN;ix++){
			int ixLeft = ix*yN;
			int ixRight = (ix+1)%lngN * yN;
			for(int iy=0;iy<latN;iy++){
				int iyUp = iy-1;
				int iyDown = iy;
				if(iy==0){
					addIndex(
						0,
						2+ixLeft+iyDown,
						2+ixRight+iyDown);

				}else if(iy==latN-1){
					addIndex(
						1,
						2+ixRight+iyUp,
						2+ixLeft+iyUp
						);
					

				}else{
					addIndex(
						2+ixRight+iyUp,
						2+ixLeft+iyUp,
						2+ixLeft+iyDown
						);
					addIndex(
						2+ixLeft+iyDown,
						2+ixRight+iyDown,
						2+ixRight+iyUp
						);

				}
			}
		}

	}
}