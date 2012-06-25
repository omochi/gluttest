#pragma once

#include "SceneRenderer.h"
namespace omgl{
	class DefaultRenderer : public SceneRenderer{
	private:
		//ツリー巡回。世界座標変換は計算済みなのでスタックしない
	public:

		bool m_DispTriangle;

		DefaultRenderer(){
			m_DispTriangle = false;
		}

		virtual void renderNode(const SceneNode *n);
		virtual void renderNodeImpl(const GLTriangles *n);
		virtual void renderScene(const Scene *scene);

	};
}