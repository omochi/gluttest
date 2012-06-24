#include "Color.h"

namespace omgl{

	Color::Color(int idx){
		Color src = ColorList[idx%ARRAY_SIZE(omgl::ColorList)];
		*this = src;
	}

	const GLfloat *Color::ptr() const{
		return glm::value_ptr(v);
	}
}