#include "Engine.h"
#include <algorithm>
#include "Actor.h"
#include "ActorHandle.h"


namespace engine{

	omgl::Scene  & Engine::scene() {
		return m_Scene;
	}
	Input & Engine::input(){
		return m_Input;
	}
	omgl::SceneRenderer & Engine::renderer(){
		return m_Renderer;
	}
	omgl::Scene & Engine::UIScene(){
		return m_UIScene;
	}
	omgl::SceneRenderer & Engine::UIRenderer(){
		return m_UIRenderer;
	}
	Rect Engine::viewport() const{
		return m_Viewport;
	}

	void Engine::setViewport(Rect v){
		m_Viewport = v;
	}
	
	vec3 Engine::transWindowToViewport(const vec3 &w) const{
		vec3 center(m_Viewport.center().x,m_Viewport.center().y,0.f);
		vec3 view = w;
		view.x = view.x - center.x;
		view.y = (m_Viewport.bottom() - view.y) - center.y;

		view.x *= 2.f/m_Viewport.width();
		view.y *= 2.f/m_Viewport.height();
		view.z = w.z;
		return view;
	}

	void Engine::addHandle(ActorHandle *h){
		ASSERT(h!=NULL);
		m_ActorHandleList.push_back(h);
	}
	void Engine::removeHandle(ActorHandle *h){
		ASSERT(h!=NULL);
		m_ActorHandleList.erase(
			std::remove(m_ActorHandleList.begin(),m_ActorHandleList.end(),h),
			m_ActorHandleList.end());
	}
	void Engine::addActor(Actor *a){
		ASSERT(a!=NULL);
		m_NewActorList.push_back(a);
	}

	void Engine::initialize(){
		//m_Scene.addChild(&m_Camera);

		m_UICamera.m_Near=-1000.f;
		m_UICamera.m_Far = 1000.f;
		m_UICamera.setPos(0,0,0);
		m_UICamera.setRotLookAt(vec3(0,0,-1),vec3(0,1,0));

		m_UIScene.addMainCamera(&m_UICamera);

		onInitialize();
	}
	void Engine::finalize(){
		onFinalize();
	}

	void Engine::update(float sec){
		
		input().update(sec);
		onUpdate(sec);
		//更新
		for(ActorList::iterator it = m_ActorList.begin();it!=m_ActorList.end();it++){
			(*it)->update(sec);
		}
		//ハンドラ更新
		for(ActorHandleList::iterator it = m_ActorHandleList.begin();it!=m_ActorHandleList.end();it++){
			(*it)->update();
		}

		//死亡削除
		for(ActorList::iterator it = m_ActorList.begin();it!=m_ActorList.end();it++){
			if((*it)->m_Delete){
				(*it)->finalize();
				delete (*it);//むむむむむ
				it=m_ActorList.erase(it);
			}
		}

		//描画情報更新
		m_Scene.updateWorldTransform();
		m_UIScene.updateWorldTransform();


		//生成
		for(ActorList::iterator it = m_NewActorList.begin();it!=m_NewActorList.end();it++){
			m_ActorList.push_back(*it);
			(*it)->initialize(this);
		}
		m_NewActorList.clear();
		
	}
	void Engine::render(){
		glViewport(m_Viewport.left(),m_Viewport.top(),
			m_Viewport.width(),m_Viewport.height());

		glClearColor(0.0f,0.0f,0.0f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		omgl::Camera *cam = m_Scene.getMainCamera();
		if(cam!=NULL){
			cam->m_Width = m_Viewport.width();
			cam->m_Height = m_Viewport.height();
			m_Renderer.renderScene(&m_Scene,cam);
		}

		glClear(GL_DEPTH_BUFFER_BIT);
		m_UICamera.m_Width = m_Viewport.width();
		m_UICamera.m_Height = m_Viewport.height();
		m_UIRenderer.renderScene(&m_UIScene,&m_UICamera);
	}
}