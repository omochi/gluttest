#include "SceneNodeIdPool.h"

namespace omgl{
	uint SceneNodeIdPool::genId(){
		uint ret = 0;
		if(freeList.size() == 0){
			ret = nextId;
			nextId ++;
		}else{
			ret = freeList.front();
			freeList.pop_front();
		}

		return ret;
	}
	void SceneNodeIdPool::releaseId(uint id){
		freeList.push_back(id);
	}
}