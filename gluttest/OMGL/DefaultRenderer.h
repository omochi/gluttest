#pragma once

#include "SceneRenderer.h"
namespace omgl{
	class DefaultRenderer : public SceneRenderer{
	private:
		//�c���[����B���E���W�ϊ��͌v�Z�ς݂Ȃ̂ŃX�^�b�N���Ȃ�
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