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

		m_Vertices.resize(3*(2+yN*xN));
		m_Indices.resize(3*(2*lngN + 2*(latN-1)*lngN));

		m_Vertices[0] = 0;
		m_Vertices[1] = 0.5f;
		m_Vertices[2] = 0;
		m_Vertices[3] = 0;
		m_Vertices[4] = -0.5f;
		m_Vertices[5] = 0;

		float angX = M_2PI / lngN;
		float angY = M_PI / latN;

		int vertexIdx = 6;
		for(int ix = 0; ix < xN;ix++){
			float lng = angX * ix;
			for(int iy = 0;iy < yN; iy++){
				float lat = angY * (iy+1);
				m_Vertices[vertexIdx+0] = 0.5f * glm::sin(lng) * glm::sin(lat); 
				m_Vertices[vertexIdx+1] = 0.5f * glm::cos(lat);
				m_Vertices[vertexIdx+2] = 0.5f * glm::cos(lng) * glm::sin(lat);
				vertexIdx += 3;
			}
		}

		int indexIdx= 0;
		for(int ix = 0;ix < lngN;ix++){
			int ixLeft = ix*yN;
			int ixRight = (ix+1)%lngN * yN;
			for(int iy=0;iy<latN;iy++){
				int iyUp = iy-1;
				int iyDown = iy;
				if(iy==0){
					m_Indices[indexIdx+0]=0;
					m_Indices[indexIdx+1]=2+ixLeft+iyDown;
					m_Indices[indexIdx+2]=2+ixRight+iyDown;
					indexIdx+=3;
				}else if(iy==latN-1){
					m_Indices[indexIdx+0]=1;
					m_Indices[indexIdx+1]=2+ixRight+iyUp;
					m_Indices[indexIdx+2]=2+ixLeft+iyUp;
					indexIdx+=3;
				}else{
					m_Indices[indexIdx+0]=2+ixRight+iyUp;
					m_Indices[indexIdx+1]=2+ixLeft+iyUp;
					m_Indices[indexIdx+2]=2+ixLeft+iyDown;

					m_Indices[indexIdx+3]=2+ixLeft+iyDown;
					m_Indices[indexIdx+4]=2+ixRight+iyDown;
					m_Indices[indexIdx+5]=2+ixRight+iyUp;
					indexIdx+=6;
				}
			}
		}

	}
}