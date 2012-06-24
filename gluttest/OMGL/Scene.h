#pragma once

#include "SceneNode.h"
#include "Camera.h"

//�c���[���̂��߂�Node���p���B
//�V�[�����̂̕ϊ��͖�������

namespace omgl{
	class Scene : public SceneNode{
	private:
		//���
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