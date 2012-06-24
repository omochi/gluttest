#include "GLTriangles.h"
namespace omgl{
	const Color &GLTriangles::getColor() const{
		return m_Color;
	}
	void GLTriangles::setColor(const Color &c){
		m_Color = c;
	}

}