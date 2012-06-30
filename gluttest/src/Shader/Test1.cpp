#include "Test1.h"

using namespace omgl;

Test1Shader::Test1Shader():omgl::GLProgram(),omgl::SceneRenderer(){
	m_DebugLineEnabled = false;
	m_DebugNormalEnabled = false;
	m_ModelEnabled = true;
	m_NormalEnabled = true;
	m_NormalColorView = false;
};

void Test1Shader::onPreLink(){
	bindAttrib(ATTR_POS,"aPos");
	bindAttrib(ATTR_NORMAL,"aNormal");
}
void Test1Shader::onPostLink(){
	unis[UNI_MODEL] = getUniform("uModel");
	unis[UNI_VIEWING] = getUniform("uViewing");
	unis[UNI_PROJECTION] = getUniform("uProjection");
	unis[UNI_COLOR] = getUniform("uColor");
	unis[UNI_NORMAL_ENABLED] = getUniform("uNormalEnabled");
	unis[UNI_NORMAL_COLOR_VIEW] = getUniform("uNormalColorView");
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
	glUniform1i(unis[UNI_NORMAL_ENABLED],m_NormalEnabled && n.m_NormalEnabled);
		
	if(m_ModelEnabled){
		glEnable(GL_DEPTH_TEST);
		drawElementsPN(n.m_BeginMode,n.m_VertexBuf,n.m_IndexBuf);
	}

	if(m_DebugLineEnabled){

		if(n.m_BeginMode==GL_TRIANGLES){
			//omgl::DebugLines line;
			//line.col = omgl::ColorGreen;
			//line.world = model;
			int i=0;
			for(int i=0;i<static_cast<int>(n.m_Indices.size());i+=3){
				vec3 p[3];
				for(int j=0;j<3;j++){
					p[j] = glm::vec3(glm::mul(model,glm::vec4(n.getVertexByElementIndex(i+j).pos,1.f)));
				}


//				p[0] = n.getVertexByElementIndex(i+0).pos;
//				p[1] = n.getVertexByElementIndex(i+1).pos;
//				p[2] = n.getVertexByElementIndex(i+2).pos;
				
				m_DebugWires.posList.push_back(p[0]);
				m_DebugWires.posList.push_back(p[1]);
				m_DebugWires.posList.push_back(p[1]);
				m_DebugWires.posList.push_back(p[2]);
				m_DebugWires.posList.push_back(p[2]);
				m_DebugWires.posList.push_back(p[0]);
			}
			//addDebugLines(line);
		}
		
	}
	if(m_DebugNormalEnabled){
	//	omgl::DebugLines line;
	//	line.col = omgl::ColorOrange;
	//	line.world = mat(1);

		for(int i=0;i<static_cast<int>(n.m_Vertices.size());i++){
			vec3 p[2];
			p[0] = glm::vec3(glm::mul(model,glm::vec4(n.m_Vertices[i].pos,1.f)));
			p[1] = p[0] + glm::normalize(glm::mul(modelNormal,n.m_Vertices[i].normal)) * 0.1f;

			m_DebugNormals.posList.push_back(p[0]);
			m_DebugNormals.posList.push_back(p[1]);

		//	line.posList.push_back(p[0]);
		//	line.posList.push_back(p[1]);
		}

	//	addDebugLines(line);

	}
}

void Test1Shader::drawDebugLines(const omgl::DebugLines &line){
	if(line.posList.size()==0)return;
	
	glUniform1i(unis[UNI_NORMAL_ENABLED],false);
	glUniform4fv(unis[UNI_COLOR],1,glm::value_ptr(line.col));
	glUniformMatrix4fv(unis[UNI_MODEL],1,GL_FALSE,glm::value_ptr(line.world));

	std::vector<GLfloat> vBuf;

	for(int i=0;i<static_cast<int>(line.posList.size());i++){
		vBuf.push_back(line.posList[i].x);
		vBuf.push_back(line.posList[i].y);
		vBuf.push_back(line.posList[i].z);
	}

	glEnableVertexAttribArray(ATTR_POS);
	glVertexAttribPointer(ATTR_POS,3,GL_FLOAT,GL_FALSE,0,&vBuf[0]);

	glDrawArrays(GL_LINES,0,line.posList.size());

	glDisableVertexAttribArray(ATTR_POS);
}

void Test1Shader::renderScene(const omgl::Scene &scene){

	m_DebugLines.clear();

	m_DebugWires.col = omgl::ColorGreen;
	m_DebugWires.world = mat(1);
	m_DebugWires.posList.clear();


	m_DebugNormals.col = omgl::ColorOrange;
	m_DebugNormals.world = mat(1);
	m_DebugNormals.posList.clear();

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
	glUniform3fv(unis[UNI_DIRECTION],1,glm::value_ptr(glm::normalize(m_Direction)));
	glUniform3fv(unis[UNI_DIRECTION_COLOR],1,glm::value_ptr(m_DirectionColor));

	glUniform1i(unis[UNI_NORMAL_COLOR_VIEW],m_NormalColorView);

	walkNode(scene);

	glDisable(GL_DEPTH_TEST);
	for(std::vector<omgl::DebugLines>::iterator it = m_DebugLines.begin();it!=m_DebugLines.end();it++){
		drawDebugLines(*it);
	}

	drawDebugLines(m_DebugWires);
	drawDebugLines(m_DebugNormals);

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

omgl::DebugLines &Test1Shader::addDebugLines(const omgl::DebugLines &line){
	m_DebugLines.push_back(line);
	return m_DebugLines.back();
}