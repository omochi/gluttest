#include "Cube.h"

namespace omgl{
	Cube::Cube():SceneNode(){
		m_Up.setPos(0,0.5,0);
		m_Up.setRotEular(-M_PI_2,0,0);
		m_Up.setColor(ColorBlue);

		m_Left.setPos(-0.5,0,0);
		m_Left.setRotEular(0,-M_PI_2,0);
		m_Left.setColor(ColorYellow);

		m_Front.setPos(0,0,+0.5);
		m_Front.setRotEular(0,0,0);
		m_Front.setColor(ColorRed);

		m_Right.setPos(0.5,0,0);
		m_Right.setRotEular(0,+M_PI_2,0);
		m_Right.setColor(ColorGreen);

		m_Back.setPos(0,0,-0.5);
		m_Back.setRotEular(0,M_PI,0);
		m_Back.setColor(ColorOrange);

		m_Down.setPos(0,-0.5,0);
		m_Down.setRotEular(M_PI_2,0,0);
		m_Down.setColor(ColorWhite);

		addChild(&m_Up);
		addChild(&m_Left);
		addChild(&m_Front);
		addChild(&m_Right);
		addChild(&m_Back);
		addChild(&m_Down);
	}
}