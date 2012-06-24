#include "ArrowXYZ.h"

#include "../math.h"

namespace omgl{
	ArrowXYZ::ArrowXYZ():SceneNode(){

		m_X.setRotMat(lookAt(vec3(1,0,0),vec3(0,1,0)));
		m_X.setColorAll(ColorRed);
		m_Y.setRotMat(lookAt(vec3(0,1,0),vec3(0,0,1)));
		m_Y.setColorAll(ColorGreen);
		m_Z.setRotMat(lookAt(vec3(0,0,1),vec3(1,0,0)));
		m_Z.setColorAll(ColorBlue);

		m_O.setScale(0.15f);

		addChild(&m_X);
		addChild(&m_Y);
		addChild(&m_Z);

		addChild(&m_O);
	}
}