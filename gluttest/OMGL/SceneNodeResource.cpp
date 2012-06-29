#include "SceneNodeResource.h"

namespace omgl{
	uint SceneNodeResource::getNodeId() const{
		return m_NodeId;
	}
	bool SceneNodeResource::isLoaded() const{
		return m_Loaded;
	}
	void SceneNodeResource::setLoaded(bool b){
		m_Loaded = b;
	}
		
	SceneNodeResource::SceneNodeResource(uint nodeId):
		m_NodeId(nodeId),m_Loaded(false){

	}

}