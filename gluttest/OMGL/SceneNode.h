#pragma once

#include "Transform.h"

#include <vector>
#include "SceneRenderer.h"
namespace omgl{
	class SceneNode;
	
	typedef std::vector<SceneNode *> SceneNodeList;
	class SceneNode : public Transform{
	private:
		SceneNode *m_Parent;
		SceneNodeList m_Children;

		mat m_WorldTransform;
	public:
		SceneNode():Transform(){
			m_Parent=NULL;
			m_Children=SceneNodeList();
		};

		const SceneNodeList &getChildren() const;

		void addChild(SceneNode *child);
		void removeFromParent();

		//�c���[�X�V
		const mat &getWorldTransform() const;
		void setWorldTransform(const mat &m);

		//�G�̂ł�m�[�h�͂�����p������
		virtual void render(SceneRenderer *renderer) const{};//�������Ȃ�
	};
}