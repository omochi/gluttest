#include "Actor.h"

#include <OMGL/SceneNode.h>

namespace engine{

	omgl::SceneNode *Actor::getSceneNode() const{
		return m_SceneNode;
	}
	void Actor::setSceneNode(omgl::SceneNode *n){
		m_SceneNode = n;
	}
	void Actor::initialize(Engine *e){
		m_Engine = e;
		onInitialize();
	}
	void Actor::finalize(){
		onFinalize();
	}
	void Actor::update(float sec){
		onUpdate(sec);
		//座標を転送
		if(m_SceneNode!=NULL){
			m_SceneNode->setTransform(static_cast<omgl::Transform>(*this));
		}
	}

}