#pragma once
#include "../SceneNode.h"

#include "../Color.h"

namespace omgl{
	class GLTriangles : public SceneNode{
	private:
		Color m_Color;
		
	public:
		bool m_ColorEnabled;
		GLenum m_BeginMode;
		std::vector<GLfloat> m_Vertices;
		std::vector<GLuint> m_Indices;

		const Color &getColor() const;
		void setColor(const Color &c);

		GLTriangles():SceneNode(),m_BeginMode(GL_TRIANGLES){}
		virtual void render(SceneRenderer *renderer) const{renderer->renderNode(this);}
	};
}