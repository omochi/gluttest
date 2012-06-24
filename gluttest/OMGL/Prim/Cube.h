#pragma once

#include "../SceneNode.h"
#include "Square.h"

namespace omgl{
	//Square x 6
	//ルービックキューブ配色
	class Cube : public SceneNode{
	public:
		Square m_Up;
		Square m_Left;
		Square m_Front;
		Square m_Right;
		Square m_Back;
		Square m_Down;
		Cube();
	};
}