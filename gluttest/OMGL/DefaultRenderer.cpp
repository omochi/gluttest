#include "DefaultRenderer.h"

#include "Scene.h"
#include "Camera.h"
#include "SceneNode.h"
#include "Prim/GLTriangles.h"

namespace omgl{
	void DefaultRenderer::renderNode(const SceneNode *n){
		ASSERT(n!=NULL);
		glPushMatrix();
		glMultMatrixf(glm::value_ptr(n->getWorldTransform()));
		n->visitRenderer(this);
		glPopMatrix();
	}

	void DefaultRenderer::renderNodeImpl(const GLTriangles *n){
		ASSERT(n!=NULL);

		glColor4fv(n->getColor().ptr());

		glEnable(GL_DEPTH_TEST);
		glBegin(n->m_BeginMode);
		for(std::vector<GLuint>::const_iterator i = n->m_Indices.begin();i!=n->m_Indices.end();i++){
			int idx = *i;
			glVertex3fv(&n->m_Vertices[idx*3]);
		}
		glEnd();

		if(m_DispTriangle){
			glDisable(GL_DEPTH_TEST);
			glColor4f(0,1,0,1);
			glBegin(GL_LINES);
			int i=0;
			while(i+2<static_cast<int>(n->m_Indices.size())){
				glVertex3fv(&n->m_Vertices[n->m_Indices[i+0]*3]);
				glVertex3fv(&n->m_Vertices[n->m_Indices[i+1]*3]);

				glVertex3fv(&n->m_Vertices[n->m_Indices[i+1]*3]);
				glVertex3fv(&n->m_Vertices[n->m_Indices[i+2]*3]);

				glVertex3fv(&n->m_Vertices[n->m_Indices[i+2]*3]);
				glVertex3fv(&n->m_Vertices[n->m_Indices[i+0]*3]);

				i+=3;
			}
			glEnd();
		}
	}

	void DefaultRenderer::renderScene(const Scene *scene){
		ASSERT(scene!=NULL);
		Camera *cam = scene->getMainCamera();
		
		glEnable(GL_DEPTH_TEST);
		glCullFace(GL_BACK);
		glEnable(GL_CULL_FACE);
		glDepthMask(GL_TRUE);

		glMatrixMode(GL_PROJECTION);

		mat projection = cam->getProjection();
		glLoadMatrixf(glm::value_ptr(projection));		
	
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glPushMatrix();
		glMultMatrixf(glm::value_ptr(cam->getViewing()));
		walkNode(scene);

		glPopMatrix();

	}
}