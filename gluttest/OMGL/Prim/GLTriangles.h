#pragma once
#include "../SceneNode.h"
#include "../Color.h"
#include "../GLBufferObject.h"

namespace omgl{
	class GLTriangles : public SceneNode{
	private:
		Color m_Color;
		
	public:
		GLenum m_BeginMode;
		std::vector<GLfloat> m_Vertices;
		std::vector<GLuint> m_Indices;

		GLBufferObject m_VertexBuf;
		GLBufferObject m_IndexBuf;



		const Color &getColor() const;
		void setColor(const Color &c);

		GLTriangles():SceneNode(),m_BeginMode(GL_TRIANGLES){}
		
		SCENE_RENDERER_IMPL_VISIT_RENDERER();

	protected:
		virtual bool loadImpl();
		virtual void releaseImpl();

	};
}