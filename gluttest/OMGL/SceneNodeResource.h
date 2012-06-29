#pragma once
#include "common.h"
#include "GLBufferObject.h"
namespace omgl{
	class SceneNodeResource{
	private:
		uint m_NodeId;
		bool m_Loaded;
	public:
		uint getNodeId() const;
		bool isLoaded() const;
		void setLoaded(bool b);
		SceneNodeResource(uint nodeId);

		GLBufferObject m_VertexBuf; 
		GLBufferObject m_IndexBuf;

	protected:
	};
}