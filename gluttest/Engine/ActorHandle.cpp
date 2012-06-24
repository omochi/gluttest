#include "ActorHandle.h"

#include "Engine.h"

namespace engine{
	ActorHandle::ActorHandle(Engine &e,Actor &a):m_Engine(e){
		m_Ptr = &a;
		m_Engine.addHandle(this);
	}
	ActorHandle::~ActorHandle(){
		m_Engine.removeHandle(this);
	}
	void ActorHandle::update(){
		if(m_Ptr!=NULL){
			if(m_Ptr->m_Delete)m_Ptr=NULL;
		}
	}
	Actor *ActorHandle::ptr() const{
		return m_Ptr;
	}
	bool ActorHandle::isValid() const{
		return m_Ptr!=NULL;
	}

}