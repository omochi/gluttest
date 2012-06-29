#pragma once
#include "common.h"
#include "Transform.h"
#include "SceneRenderer.h"

#define SCENE_NODE_IMPL_VISIT_RENDERER() \
	virtual void visitRenderer(omgl::SceneRenderer &r)const{ r.renderNodeImpl(*this); } \
	virtual bool visitLoadNode(omgl::SceneRenderer &r){ return r.loadNodeImpl(*this); }\
	virtual void visitReleaseNode(omgl::SceneRenderer &r){ r.releaseNodeImpl(*this); }\


namespace omgl{
	class SceneNode;
	
	typedef std::vector<SceneNode *> SceneNodeList;
	class SceneNode : public Transform{
	private:
		SceneNode *m_Parent;
		SceneNodeList m_Children;

		mat m_WorldTransform;	
	public:
		SceneNode():Transform(),m_Parent(NULL){
			m_Children = SceneNodeList();
		};

		const SceneNodeList &getChildren() const;

		void addChild(SceneNode *child);

		SceneNodeList::iterator removeChild(SceneNode *child);

		void removeFromParent();
		SceneNode *getParent() const;

		//ツリー更新
		const mat &getWorldTransform() const;
		void setWorldTransform(const mat &m);

		SCENE_NODE_IMPL_VISIT_RENDERER();

	};
}