#pragma once
#include "../SceneNode.h"
#include "../Color.h"
#include "../GLBufferObject.h"
#include "Vertex.h"

namespace omgl{
	class GLTriangles : public SceneNode{
	private:
		Color m_Color;
		
	public:
		GLenum m_BeginMode;
		
		std::vector<Vertex> m_Vertices;
		std::vector<GLuint> m_Indices;

		GLBufferObject m_VertexBuf;
		GLBufferObject m_IndexBuf;

		Vertex &addVertex(const Vertex &v);

		void addIndex(int i);
		void addIndex(int i0,int i1,int i2);

		int getIndexByElementIndex(int i) const;
		const Vertex &getVertexByElementIndex(int i) const; 

		const Color &getColor() const;
		void setColor(const Color &c);

		GLTriangles():SceneNode(),m_BeginMode(GL_TRIANGLES){}
		
		SCENE_NODE_IMPL_VISIT_RENDERER();

		/*
	protected:
		virtual bool loadImpl();
		virtual void releaseImpl();
		*/
	};
}