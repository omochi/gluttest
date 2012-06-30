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

		float m_PrevProfileTime;
		int m_RenderCount;
		int m_ProfileFps;

		
		float getCurrentTime();


	protected:
		omgl::Scene m_UIScene;

		omgl::OrthoCamera m_UICamera;
	public:
		int getProfileFps() const;
		omgl::Scene & scene() ;
		Input & input();

		omgl::Scene & UIScene();

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

		void render();
	protected:
		virtual void onInitialize(){};
		virtual void onFinalize(){};
		virtual void onUpdate(float sec){};
		virtual void onRender(){};
		virtual void onProfileFps(){};
	};
}