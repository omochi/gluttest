#include "Arrow.h"

namespace omgl{
	Arrow::Arrow():SceneNode(){
		m_Body.setDivNum(6);
		m_Body.setScale(0.05f,0.05f,1.0f);
		m_Head.setDivNum(10);
		m_Head.setScale(0.2f,0.2f,1.0f);
		addChild(&m_Body);
		addChild(&m_Head);
		setLength(0.8f,0.2f);
	}
	void Arrow::setLength(float body,float head){
		vec3 scale = m_Body.getScale();
		scale.z = body;
		m_Body.setScale(scale);
		m_Body.setPos(0,0,body/2.f);
		scale = m_Head.getScale();
		scale.z = head;
		m_Head.setScale(scale);
		m_Head.setPos(0,0,body);
	}
	void Arrow::setColorAll(const Color &c){
		m_Body.setColorAll(c);
		m_Head.setColorAll(c);
	}
}