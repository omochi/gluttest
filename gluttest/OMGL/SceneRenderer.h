#pragma once

#include "OMGL.h"

#include <gl/glut.h>

namespace omgl{
	class SceneNode;
	class Scene;
	class Camera;
	class GLTriangles;
	class TriangleStrip;
	class Square;
	class Circle;

	class SceneRenderer{
	private:
		//ツリー巡回。世界座標変換は計算済みなのでスタックしない
		void walkNode(const SceneNode *node);
	public:
		bool m_DispTriangle;

		SceneRenderer(){
			m_DispTriangle = false;
		}

		void renderNode(const GLTriangles *n);


		void renderScene(const Scene *scene);
		void renderScene(const Scene *scene,const Camera *camera);

	};
}