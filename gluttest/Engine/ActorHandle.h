#pragma once
#include "Actor.h"

namespace engine{
	class Engine;
	class ActorHandle{
	private:
		Engine &m_Engine;
		Actor *m_Ptr;
	public:
		ActorHandle(Engine &e,Actor &a);
		virtual ~ActorHandle();
		void update();
		Actor *ptr() const;
		bool isValid() const;
	};
}