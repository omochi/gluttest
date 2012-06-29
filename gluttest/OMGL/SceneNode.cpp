#include "SceneNode.h"

namespace omgl{

	
	void SceneNode::addChild(SceneNode *child){
		ASSERT(m_Parent==NULL);//循環防止
		m_Children.push_back(child);
		child->m_Parent = this;
	}

	SceneNodeList::iterator SceneNode::removeChild(SceneNode *child){
		ASSERT(child!=NULL);
		SceneNodeList::iterator it = std::remove(m_Children.begin(),m_Children.end(),child);
		if(it!=m_Children.end()){
			child->m_Parent = NULL;
		}
		return m_Children.erase(it,m_Children.end());
	}

	void SceneNode::removeFromParent(){
		if(m_Parent!=NULL)m_Parent->removeChild(this);
	}

	const SceneNodeList &SceneNode::getChildren() const{
		return m_Children;
	}
	SceneNode *SceneNode::getParent() const{
		return m_Parent;
	}

	const mat &SceneNode::getWorldTransform() const{
		return m_WorldTransform;
	}

	void SceneNode::setWorldTransform(const mat &m){
		m_WorldTransform = m;
	}

	mat3 SceneNode::getWorldNormalMatrix() const{
		return glm::inverseTranspose(glm::mat3(getWorldTransform()));
	}


}