#pragma once

#include "Camera.h"

namespace omgl{
	class ParseCamera : public Camera{
	public:
		float m_Fovy;
		ParseCamera():Camera(){
			m_Fovy  = 60.f;
		}
		virtual mat getProjection() const;
	};
}