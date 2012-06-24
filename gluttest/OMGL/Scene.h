#pragma once

#include "SceneNode.h"
#include "Camera.h"

//ツリー化のためにNodeを継承。
//シーン自体の変換は無視する

namespace omgl{
	class Scene : public SceneNode{
	private:
		//一個
		Camera *m_MainCamera;
	public:
		Camera *getMainCamera() const;
		void setMainCamera(Camera *camera);

		//addChild
		void addMainCamera(Camera *cam);

		void updateWorldTransform();
		void updateWorldTransform(SceneNode *node,const mat &base);

	};
}