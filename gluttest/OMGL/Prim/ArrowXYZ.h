#pragma once

#include "Arrow.h"
#include "Sphere.h"
namespace omgl{
	class ArrowXYZ : public SceneNode{
	public:
		Arrow m_X,m_Y,m_Z;
		Sphere m_O;
		ArrowXYZ();
	};

}