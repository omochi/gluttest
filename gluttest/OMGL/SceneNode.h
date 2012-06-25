#pragma once

#include "Transform.h"
#include "SceneRenderer.h"
namespace omgl{
	class SceneNode;
	
	typedef std::vector<SceneNode *> SceneNodeList;
	class SceneNode : public Transform{
	private:
		SceneNode *m_Parent;
		SceneNodeList m_Children;

		mat m_WorldTransform;

		bool m_Loaded;
		bool m_LoadReq;
	public:
		SceneNode():Transform(){
			m_Parent=NULL;
			m_Loaded = false;
			m_LoadReq = true;
			m_Children=SceneNodeList();
		};
		const SceneNodeList &getChildren() const;

		void addChild(SceneNode *child);
		void removeFromParent();
		SceneNode *getParent() const;

		//ツリー更新
		const mat &getWorldTransform() const;
		void setWorldTransform(const mat &m);

		//絵のでるノードは以下を記述
		//SCENE_RENDERER_IMPL_VISIT_RENDERER();
		virtual void visitRenderer(omgl::SceneRenderer *r)const{  }

		bool isLoaded() const;
		bool isLoadRequesting() const;

		//読み込み
		bool load();
		//解放
		void release();
	protected:
		virtual bool loadImpl(){ return true; }
		virtual void releaseImpl(){}


	};
}