#include "Square.h"	

namespace omgl{
	Square::Square():GLTriangles(){
		//m_BeginMode = GL_TRIANGLE_STRIP;

		m_Vertices.resize(3*4);
		m_Vertices[0]=0.5f;
		m_Vertices[1]=0.5f;
		m_Vertices[2]=0.0f;

		m_Vertices[3]=-0.5f;
		m_Vertices[4]=0.5f;
		m_Vertices[5]=0.0f;
		
		m_Vertices[6]=-0.5f;
		m_Vertices[7]=-0.5f;
		m_Vertices[8]=0.0f;
		
		m_Vertices[9]=0.5f;
		m_Vertices[10]=-0.5f;
		m_Vertices[11]=0.0f;

		m_Indices.resize(3*2);
		m_Indices[0] = 0;
		m_Indices[1] = 1;
		m_Indices[2] = 2;

		m_Indices[3] = 2;
		m_Indices[4] = 3;
		m_Indices[5] = 0;
	}
}