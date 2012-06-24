#pragma once

#include <OMGL/Transform.h>
#include <OMGL/SceneNode.h>

namespace Engine{

	class Actor : public OMGL::Transform{
	private:
		OMGL::SceneNode *m_SceneNode;
	public:
		bool m_Delete;

		Actor():OMGL::Transform(){
			m_SceneNode=NULL;
		}
	
		OMGL::SceneNode *getSceneNode() const;
		void setSceneNode(OMGL::SceneNode *n);
		void update(float sec);
	protected:
		//���[�U��`�����낵
		void onUpdate(float sec){};
	};

}