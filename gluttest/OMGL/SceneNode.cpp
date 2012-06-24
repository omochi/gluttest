#include "SceneNode.h"
#include <algorithm>
#include "SceneRenderer.h"
namespace omgl{

	void SceneNode::addChild(SceneNode *child){
		ASSERT(m_Parent==NULL);//循環防止
		m_Children.push_back(child);
	}
	void SceneNode::removeFromParent(){
		if(m_Parent!=NULL){
			SceneNodeList::iterator it = std::remove(m_Parent->m_Children.begin(),m_Parent->m_Children.end(),this);
			m_Parent->m_Children.erase(it,m_Parent->m_Children.end());
		}
		m_Parent=NULL;
	}

	const SceneNodeList &SceneNode::getChildren() const{
		return m_Children;
	}

	const mat &SceneNode::getWorldTransform() const{
		return m_WorldTransform;
	}

	void SceneNode::setWorldTransform(const mat &m){
		m_WorldTransform = m;
	}

}