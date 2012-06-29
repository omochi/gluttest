#pragma once

#include "common.h"

namespace omgl{
	class SceneNode;
	class Scene;
	class Camera;
	class GLTriangles;
	class TriangleStrip;
	class Square;
	class Circle;
	class SceneNodeResource;
}

#define SCENE_RENDERER_IMPL_ACCEPTOR_CLASS(klass)\
	virtual void renderNodeImpl(const klass &n){}\
	virtual bool loadNodeImpl(klass &n){return true;}\
	virtual void releaseNodeImpl(klass &n){}\



namespace omgl{
	class SceneRenderer{
	private:


	protected:
		void walkNode(const SceneNode &node);
		typedef bool (SceneRenderer::*NodeMethod)(SceneNode &n);
		bool walkNode(SceneNode &node,NodeMethod method);
	public:
		void renderNode(const SceneNode &n);
		virtual void renderScene(const Scene &scene) = 0;

		virtual bool addNode(SceneNode &n){ return true;}
		virtual void removeNode(SceneNode &n){}

		//Visitorパターン Acceptメソッド
		SCENE_RENDERER_IMPL_ACCEPTOR_CLASS(SceneNode);
		SCENE_RENDERER_IMPL_ACCEPTOR_CLASS(GLTriangles);
		

//		virtual bool loadNode(SceneNode &n){ return true; }
	//	virtual void releaseNode(SceneNode &n){}

	};
}