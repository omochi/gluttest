#pragma once
#include "../SceneNode.h"
#include "Cone.h"
#include "Cylinder.h"

namespace omgl{
	class Arrow:public SceneNode{
	public:
		Cone m_Head;
		Cylinder m_Body;
		Arrow();
		void setLength(float body,float head);
		void setColorAll(const Color &c);
	};
}