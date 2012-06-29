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

		bool m_NormalEnabled;

		Vertex &addVertex();
		Vertex &addVertex(const Vertex &v);

		//pos
		Vertex &addVertex(const vec3 &p);
		Vertex &addVertex(float x,float y,float z);

		void addIndex(int i);
		void addIndex(int i0,int i1,int i2);

		int getIndexByElementIndex(int i) const;
		const Vertex &getVertexByElementIndex(int i) const; 

		const Color &getColor() const;
		void setColor(const Color &c);

		GLTriangles():SceneNode(),m_BeginMode(GL_TRIANGLES),
			m_Color(1.f,1.f,1.f,1.f),m_NormalEnabled(true){}
		
		SCENE_NODE_IMPL_VISIT_RENDERER();


		/*
	protected:
		virtual bool loadImpl();
		virtual void releaseImpl();
		*/
	};
}