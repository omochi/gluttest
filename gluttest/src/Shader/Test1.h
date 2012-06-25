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

protected:
	virtual std::string getVshPath(){ return "shader/test1.vsh"; };
	virtual std::string getFshPath(){ return "shader/test1.fsh"; };
	virtual void onPreLink(){
		bindAttrib(ATTR_POS,"position");
	}
	virtual void onPostLink(){
		unis[UNI_MODEL] = getUniform("model");
		unis[UNI_VIEWING] = getUniform("viewing");
		unis[UNI_PROJECTION] = getUniform("projection");
		unis[UNI_COLOR] = getUniform("color");
	}
public:
	virtual void renderScene(const omgl::Scene *scene);

	virtual void renderNodeImpl(const omgl::GLTriangles *n);
};

