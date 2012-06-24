#pragma once

#include <OMBase/OMBase.h>
#include <OMGL/OMGL.h>

#include "Input.h"

namespace engine{
	class Actor;
	class ActorHandle;
	typedef std::vector<Actor *> ActorList;
	typedef std::vector<ActorHandle *> ActorHandleList;
	class Engine{
	private:
		Input m_Input;

		Rect m_Viewport;

		ActorList m_ActorList;
		ActorList m_NewActorList;

		ActorHandleList m_ActorHandleList;

		omgl::Scene m_Scene;
		omgl::SceneRenderer m_Renderer;

		omgl::Scene m_UIScene;
		omgl::SceneRenderer m_UIRenderer;
		omgl::OrthoCamera m_UICamera;
	public:
		omgl::Scene & scene() ;
		Input & input();
		omgl::SceneRenderer & renderer();
		omgl::Scene & UIScene();
		omgl::SceneRenderer & UIRenderer();
		Rect viewport() const;

		void setViewport(Rect v);
		vec3 transWindowToViewport(const vec3 &v) const;

		void initialize();
		void finalize();

		//Actorは中でdeleteされうる
		void update(float sec);
		void addHandle(ActorHandle *h);
		void removeHandle(ActorHandle *h);

		//所有権を渡す
		void addActor(Actor *a);

		virtual void render();
	protected:
		virtual void onInitialize(){};
		virtual void onFinalize(){};
		virtual void onUpdate(float sec){};
	};
}