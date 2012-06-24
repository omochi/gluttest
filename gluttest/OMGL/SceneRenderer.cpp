#include "SceneRenderer.h"

#include "Scene.h"
#include "Camera.h"

#include "Prim/GLTriangles.h"


namespace omgl{

	void SceneRenderer::walkNode(const SceneNode *node){
		ASSERT(node!=NULL);
		glPushMatrix();
		glMultMatrixf(glm::value_ptr(node->getWorldTransform()));
		node->render(this);
		glPopMatrix();

		for(SceneNodeList::const_iterator it = node->getChildren().begin();it!=node->getChildren().end();it++){
			walkNode(*it);
		}
	}

	void SceneRenderer::renderNode(const GLTriangles *n){
		ASSERT(n!=NULL);
		if(n->m_ColorEnabled){
			glColor4fv(n->getColor().ptr());
		}
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



	void SceneRenderer::renderScene(const Scene *scene){
		ASSERT(scene!=NULL);
		Camera *cam = scene->getMainCamera();
		renderScene(scene,cam);
	}
	void SceneRenderer::renderScene(const Scene *scene,const Camera *camera){
		ASSERT(scene!=NULL);
		ASSERT(camera!=NULL);
		
		glEnable(GL_DEPTH_TEST);
		glCullFace(GL_BACK);
		glEnable(GL_CULL_FACE);
		glDepthMask(GL_TRUE);

		glMatrixMode(GL_PROJECTION);

		mat projection = camera->getProjection();
		glLoadMatrixf(glm::value_ptr(projection));		
	
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glPushMatrix();
		glMultMatrixf(glm::value_ptr(camera->getViewing()));
		walkNode(scene);

		glPopMatrix();

	}
}