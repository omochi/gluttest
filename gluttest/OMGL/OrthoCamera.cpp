#include "OrthoCamera.h"

namespace omgl{
	mat OrthoCamera::getProjection() const{

		float w2 = m_Width/2.f;
		float h2 = m_Height/2.f;
		mat m = glm::ortho(-w2,w2,-h2,h2,m_Near,m_Far);
		m[0][0]=-m[0][0];
		m[2][2]=-m[2][2];
		return m;
	}
}