#include "Scene.h"

namespace omgl{
	void Scene::updateNode(SceneNode *node){
		ASSERT(node!=NULL);
		//座標変換
		SceneNode *p = node->getParent();
		mat transform = node->getTransform();
		if(p){
			//親が無い(Sceneルート)は変換しない
			node->setWorldTransform(glm::mul(p->getWorldTransform(),transform));

		}

		//子供のノードへ進む
		for(SceneNodeList::const_iterator it = node->getChildren().begin();it!=node->getChildren().end();it++){
			updateNode(*it);
		}
	}

	Camera *Scene::getMainCamera() const{
		return m_MainCamera;
	}

	void Scene::setMainCamera(Camera *camera){
		m_MainCamera = camera;
	}
	void Scene::addMainCamera(Camera *cam){
		setMainCamera(cam);
		addChild(cam);
	}

	void Scene::update(){
		setWorldTransform(mat(1.f));

		updateNode(this);
	}

}