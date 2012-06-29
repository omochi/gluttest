#pragma once

#include <OMGL/OMGL.h>

class Test1Shader : public omgl::GLProgram , omgl::SceneRenderer{
public:
	enum{
		ATTR_POS = 0,
		ATTR_COUNT
	};
	//GLint attrs[ATTR_COUNT];
	enum{
		UNI_MODEL,
		UNI_VIEWING,
		UNI_PROJECTION,
		UNI_COLOR,
		UNI_COUNT
	};
	GLint unis[UNI_COUNT];


	mat m_Viewing;
	mat m_Projection;

	void drawElementsP(GLenum mode,const omgl::GLBufferObject &vertexBuf,const omgl::GLBufferObject &indexBuf);

protected:
	virtual std::string getVshPath(){ return "shader/test1.vsh"; };
	virtual std::string getFshPath(){ return "shader/test1.fsh"; };
	virtual void onPreLink(){
		bindAttrib(ATTR_POS,"aPos");
	}
	virtual void onPostLink(){
		unis[UNI_MODEL] = getUniform("uModel");
		unis[UNI_VIEWING] = getUniform("uViewing");
		unis[UNI_PROJECTION] = getUniform("uProjection");
		unis[UNI_COLOR] = getUniform("uColor");
	}
public:
	bool m_DebugLine;


	virtual void renderScene(const omgl::Scene &scene);

	

	virtual bool addNode(omgl::SceneNode &n);
	virtual void removeNode(omgl::SceneNode &n);

	virtual void renderNodeImpl(const omgl::GLTriangles &n);
	virtual bool loadNodeImpl(omgl::GLTriangles &n);
	virtual void releaseNodeImpl(omgl::GLTriangles &n);


	void drawLineDebug(const std::vector<vec3> &vecs,const omgl::Color &col);
};

