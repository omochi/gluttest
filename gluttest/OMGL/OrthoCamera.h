#pragma once
#include "Camera.h"

namespace omgl{
	class OrthoCamera : public Camera{
		virtual mat getProjection() const;
	};
}