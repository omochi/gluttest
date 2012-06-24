#pragma once

#include <OMGL/Transform.h>
namespace omgl{
	class SceneNode;
}
namespace engine{
	class Engine;
	class Actor : public omgl::Transform{
	private:
		omgl::SceneNode *m_SceneNode;
	public:
		bool m_Delete;
		Engine *m_Engine;

		Actor():omgl::Transform(){
			m_SceneNode=NULL;
		}

		omgl::SceneNode *getSceneNode() const;
		void setSceneNode(omgl::SceneNode *n);

		void initialize(Engine *e);
		void finalize();
		void update(float sec);
	protected:
		//ユーザ定義するよろし
		void onInitialize(){};
		void onFinalize(){};
		void onUpdate(float sec){};
	};
}