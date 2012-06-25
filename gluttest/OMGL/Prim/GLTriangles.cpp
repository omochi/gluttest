#include "GLTriangles.h"
namespace omgl{
	const Color &GLTriangles::getColor() const{
		return m_Color;
	}
	void GLTriangles::setColor(const Color &c){
		m_Color = c;
	}

	bool GLTriangles::loadImpl(){
		if(!m_VertexBuf.load(GL_ARRAY_BUFFER,m_Vertices,GL_STATIC_DRAW)){
			release();
			return false;
		}
		if(!m_IndexBuf.load(GL_ELEMENT_ARRAY_BUFFER,m_Indices,GL_STATIC_DRAW)){
			release();
			return false;
		}

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
		ASSERT_GL();
		glBindBuffer(GL_ARRAY_BUFFER,0);
		ASSERT_GL();

		return true;
	}
	void GLTriangles::releaseImpl(){
		m_VertexBuf.release();
		m_IndexBuf.release();
	}
}