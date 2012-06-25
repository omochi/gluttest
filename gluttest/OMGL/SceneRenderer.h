#pragma once

#include "common.h"


#define SCENE_RENDERER_IMPL_VISIT_RENDERER() \
	virtual void visitRenderer(omgl::SceneRenderer *r)const{ r->renderNodeImpl(this); }

namespace omgl{
	class SceneNode;
	class Scene;
	class Camera;
	class GLTriangles;
	class TriangleStrip;
	class Square;
	class Circle;

	class SceneRenderer{
	protected:
		void walkNode(const SceneNode *node);
	public:
		virtual void renderNode(const SceneNode *n);
		virtual void renderScene(const Scene *scene) = 0;

		//Visitorパターン Acceptメソッド
		virtual void renderNodeImpl(const GLTriangles *n){};
	};
}