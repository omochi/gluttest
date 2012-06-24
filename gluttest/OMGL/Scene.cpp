#include "Scene.h"

namespace omgl{
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


	void Scene::updateWorldTransform(){
		mat mi(1.f);
		for(SceneNodeList::const_iterator it = getChildren().begin();it!=getChildren().end();it++){
			updateWorldTransform(*it,mi);
		}
	}

	void Scene::updateWorldTransform(SceneNode *node,const mat &base){
		ASSERT(node!=NULL);
		mat localTransform = node->getTransform();
		mat worldTransform = glm::mul(base,localTransform);
		node->setWorldTransform(worldTransform);

		for(SceneNodeList::const_iterator it = node->getChildren().begin();it!=node->getChildren().end();it++){
			updateWorldTransform(*it,worldTransform);
		}
	}

}