#include "Actor.h"

namespace Engine{

	OMGL::SceneNode *Actor::getSceneNode() const{
		return m_SceneNode;
	}
	void Actor::setSceneNode(OMGL::SceneNode *n){
		m_SceneNode = n;
	}

	void Actor::update(float sec){
		onUpdate(sec);
		//座標を転送
		if(m_SceneNode!=NULL){
			m_SceneNode->setTransform(static_cast<OMGL::Transform>(*this));
		}
	}

}