#include "SceneRenderer.h"

#include "SceneNode.h"

namespace omgl{
	void SceneRenderer::walkNode(const SceneNode *node){
		ASSERT(node!=NULL);
		renderNode(node);		
		for(SceneNodeList::const_iterator it = node->getChildren().begin();it!=node->getChildren().end();it++){
			walkNode(*it);
		}
	}
	void SceneRenderer::renderNode(const SceneNode *n){
		ASSERT(n!=NULL);
		n->visitRenderer(this);
	}
}