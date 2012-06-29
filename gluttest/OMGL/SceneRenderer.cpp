#include "SceneRenderer.h"

#include "SceneNode.h"
#include "SceneNodeResource.h"

namespace omgl{
	void SceneRenderer::walkNode(const SceneNode &n){
		renderNode(n);		
		for(SceneNodeList::const_iterator it = n.getChildren().begin();it!=n.getChildren().end();it++){
			walkNode(**it);
		}
	}
	bool SceneRenderer::walkNode(SceneNode &n,NodeMethod method){
		bool ok = (*this.*method)(n);
		if(!ok)return false;
		for(SceneNodeList::const_iterator it = n.getChildren().begin();it!=n.getChildren().end();it++){
			ok = walkNode(**it,method);
			if(!ok)return false;
		}
		return true;
	}

	void SceneRenderer::renderNode(const SceneNode &n){
		n.visitRenderer(*this);
	}
}