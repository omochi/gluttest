#include "Test1.h"

using namespace omgl;



void Test1Shader::renderNodeImpl(const omgl::GLTriangles *n){
	mat model = n->getWorldTransform();
	glUniformMatrix4fv(unis[UNI_MODEL],1,GL_FALSE,glm::value_ptr(model));

	glUniform4fv(unis[UNI_COLOR],1,n->getColor().ptr());

	glEnable(GL_DEPTH_TEST);

	if(!n->m_VertexBuf.bind(GL_ARRAY_BUFFER))FAIL("");
	if(!n->m_IndexBuf.bind(GL_ELEMENT_ARRAY_BUFFER))FAIL("");

	glEnableVertexAttribArray(ATTR_POS);
	glVertexAttribPointer(ATTR_POS,3,GL_FLOAT,GL_FALSE,0,0);

	glDrawElements(n->m_BeginMode,n->m_Indices.size(),GL_UNSIGNED_INT,NULL);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
	glBindBuffer(GL_ARRAY_BUFFER,0);
	
	glDisableVertexAttribArray(ATTR_POS);
}
void Test1Shader::renderScene(const omgl::Scene *scene){
	ASSERT(scene!=NULL);
	use();

	Camera *cam = scene->getMainCamera();
		
	glEnable(GL_DEPTH_TEST);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glDepthMask(GL_TRUE);

	m_Projection = cam->getProjection();
	m_Viewing = cam->getViewing();

	glUniformMatrix4fv(unis[UNI_PROJECTION],1,GL_FALSE,glm::value_ptr(m_Projection));
	glUniformMatrix4fv(unis[UNI_VIEWING],1,GL_FALSE,glm::value_ptr(m_Viewing));

	walkNode(scene);
}
