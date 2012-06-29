#include "Test1.h"

using namespace omgl;

void Test1Shader::onPreLink(){
	bindAttrib(ATTR_POS,"aPos");
	bindAttrib(ATTR_NORMAL,"aNormal");
}
void Test1Shader::onPostLink(){
	unis[UNI_MODEL] = getUniform("uModel");
	unis[UNI_VIEWING] = getUniform("uViewing");
	unis[UNI_PROJECTION] = getUniform("uProjection");
	unis[UNI_COLOR] = getUniform("uColor");
	unis[UNI_MODEL_NORMAL] = getUniform("uModelNormal");
	unis[UNI_AMBIENT] = getUniform("uAmbient");
	unis[UNI_DIRECTION] = getUniform("uDirection");
	unis[UNI_DIRECTION_COLOR] = getUniform("uDirectionColor");
}

void Test1Shader::drawElementsP(GLenum mode,const GLBufferObject &vertexBuf,const GLBufferObject &indexBuf){

	if(!vertexBuf.bind())FAIL("vertexBuf.bind");
	if(!indexBuf.bind())FAIL("indexBuf.bind");

	glEnableVertexAttribArray(ATTR_POS);
	glVertexAttribPointer(ATTR_POS,3,GL_FLOAT,GL_FALSE,0,0);
	glDrawElements(mode,indexBuf.m_DataNum,GL_UNSIGNED_INT,NULL);
	glDisableVertexAttribArray(ATTR_POS);

	if(!indexBuf.unbind())FAIL("indexBuf.unbind");
	if(!vertexBuf.unbind())FAIL("vertexBuf.unbind");
}

void Test1Shader::drawElementsPN(GLenum mode,const GLBufferObject &vertexBuf,const GLBufferObject &indexBuf){

	if(!vertexBuf.bind())FAIL("vertexBuf.bind");
	if(!indexBuf.bind())FAIL("indexBuf.bind");

	glEnableVertexAttribArray(ATTR_POS);
	glVertexAttribPointer(ATTR_POS,3,GL_FLOAT,GL_FALSE,sizeof(GLfloat)*6,OFFSET(0));
	glEnableVertexAttribArray(ATTR_NORMAL);
	glVertexAttribPointer(ATTR_NORMAL,3,GL_FLOAT,GL_FALSE,sizeof(GLfloat)*6,OFFSET(sizeof(GLfloat)*3));

	glDrawElements(mode,indexBuf.m_DataNum,GL_UNSIGNED_INT,NULL);
	glDisableVertexAttribArray(ATTR_NORMAL);
	glDisableVertexAttribArray(ATTR_POS);

	if(!indexBuf.unbind())FAIL("indexBuf.unbind");
	if(!vertexBuf.unbind())FAIL("vertexBuf.unbind");
}

void Test1Shader::renderNodeImpl(const omgl::GLTriangles &n){
	mat model = n.getWorldTransform();
	mat3 modelNormal = n.getWorldNormalMatrix();
		
	glUniformMatrix4fv(unis[UNI_MODEL],1,GL_FALSE,glm::value_ptr(model));
	glUniformMatrix3fv(unis[UNI_MODEL_NORMAL],1,GL_FALSE,glm::value_ptr(modelNormal));

	glUniform4fv(unis[UNI_COLOR],1,glm::value_ptr(n.getColor()));

	glEnable(GL_DEPTH_TEST);

	//drawElementsP(n.m_BeginMode,n.m_VertexBuf,n.m_IndexBuf);
	drawElementsPN(n.m_BeginMode,n.m_VertexBuf,n.m_IndexBuf);

	
	if(m_DebugLine){
	/*
		glDisable(GL_DEPTH_TEST);
		if(n.m_BeginMode==GL_TRIANGLES){
			std::vector<vec3> vecs;
			int i=0;
			for(int i=0;i<static_cast<int>(n.m_Indices.size());i+=3){
				vecs.clear();
				vecs.push_back(n.getVertexByElementIndex(i+0).pos);
				vecs.push_back(n.getVertexByElementIndex(i+1).pos);
				vecs.push_back(n.getVertexByElementIndex(i+2).pos);
				vecs.push_back(n.getVertexByElementIndex(i+0).pos);
				drawLineDebug(vecs,omgl::ColorGreen);
			}
		}
		*/
	}
}
void Test1Shader::renderScene(const omgl::Scene &scene){
	use();

	Camera *cam = scene.getMainCamera();

	glEnable(GL_DEPTH_TEST);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glDepthMask(GL_TRUE);

	m_Projection = cam->getProjection();
	m_Viewing = cam->getViewing();

	glUniformMatrix4fv(unis[UNI_PROJECTION],1,GL_FALSE,glm::value_ptr(m_Projection));
	glUniformMatrix4fv(unis[UNI_VIEWING],1,GL_FALSE,glm::value_ptr(m_Viewing));


	glUniform3fv(unis[UNI_AMBIENT],1,glm::value_ptr(m_Ambient));
	glUniform3fv(unis[UNI_DIRECTION],1,glm::value_ptr(m_Direction));
	glUniform3fv(unis[UNI_DIRECTION_COLOR],1,glm::value_ptr(m_DirectionColor));

	walkNode(scene);
}

bool Test1Shader::addNode(omgl::SceneNode &n){

	bool ok = n.visitLoadNode(*this);
	if(!ok)return false;
	for(SceneNodeList::const_iterator it = n.getChildren().begin();it!=n.getChildren().end();it++){
		ok = addNode(**it);
		if(!ok)return false;
	}
	return true;
}
void Test1Shader::removeNode(omgl::SceneNode &n){
	for(SceneNodeList::const_iterator it = n.getChildren().begin();it!=n.getChildren().end();it++){
		removeNode(**it);
	}
	n.visitReleaseNode(*this);
}

bool Test1Shader::loadNodeImpl(omgl::GLTriangles &n){
	std::vector<GLfloat>vBuf;
	VertexListToBufPN(vBuf,n.m_Vertices);

	if(!n.m_VertexBuf.load(GL_ARRAY_BUFFER,vBuf,GL_STATIC_DRAW)){
		releaseNodeImpl(n);
		return false;
	}

	if(!n.m_IndexBuf.load(GL_ELEMENT_ARRAY_BUFFER,n.m_Indices,GL_STATIC_DRAW)){
		releaseNodeImpl(n);
		return false;
	}

	return true;
}
void Test1Shader::releaseNodeImpl(omgl::GLTriangles &n){
	n.m_VertexBuf.release();
	n.m_IndexBuf.release();
}

void Test1Shader::drawLineDebug(const std::vector<vec3> &vecs,const omgl::Color &col){
	std::vector<GLfloat> vBuf;

	for(int i=0;i<static_cast<int>(vecs.size());i++){
		vBuf.push_back(vecs[i].x);
		vBuf.push_back(vecs[i].y);
		vBuf.push_back(vecs[i].z);
	}

	glUniform4fv(unis[UNI_COLOR],1,glm::value_ptr(col));
	
	glEnableVertexAttribArray(ATTR_POS);
	glVertexAttribPointer(ATTR_POS,3,GL_FLOAT,GL_FALSE,0,&vBuf[0]);

	glDrawArrays(GL_LINE_STRIP,0,vecs.size());

	glDisableVertexAttribArray(ATTR_POS);
}