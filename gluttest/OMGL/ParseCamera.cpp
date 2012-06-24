#include "ParseCamera.h"

namespace omgl{
	mat ParseCamera::getProjection() const{
		mat m = glm::perspectiveFov(m_Fovy,
			static_cast<float>(m_Width),static_cast<float>(m_Height),
			m_Near,m_Far);
		m[0][0]=-m[0][0];
		m[2][2]=-m[2][2];
		m[2][3]=-m[2][3];
		return m;
	}
}