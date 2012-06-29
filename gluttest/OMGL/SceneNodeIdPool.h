#pragma once
#include "common.h"
namespace omgl{
	class SceneNodeIdPool{
	private:
		std::list<uint> freeList;
		uint nextId;

		SceneNodeIdPool():nextId(1){};
	public:
		static SceneNodeIdPool &instance(){
			static SceneNodeIdPool pool;
			return pool;
		}

		//正しく使わないとぶっ壊れる
		uint genId();
		void releaseId(uint id);
	};
}