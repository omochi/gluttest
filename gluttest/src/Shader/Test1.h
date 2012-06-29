#pragma once

#include <OMGL/OMGL.h>

class Test1Shader : public omgl::GLProgram , omgl::SceneRenderer{
public:
	enum{
		ATTR_POS,
		ATTR_NORMAL,
		ATTR_COUNT
	};
	//GLint attrs[ATTR_COUNT];
	enum{
		UNI_MODEL,
		UNI_VIEWING,
		UNI_PROJECTION,
		UNI_COLOR,
		UNI_MODEL_NORMAL,
		UNI_AMBIENT,
		UNI_DIRECTION,
		UNI_DIRECTION_COLOR,
		UNI_COUNT
	};
	GLint unis[UNI_COUNT];


	mat m_Viewing;
	mat m_Projection;

	omgl::Color m_Ambient;
	vec3 m_Direction;
	omgl::Color m_DirectionColor;

	void drawElementsP(GLenum mode,const omgl::GLBufferObject &vertexBuf,const omgl::GLBufferObject &indexBuf);
	void drawElementsPN(GLenum mode,const omgl::GLBufferObject &vertexBuf,const omgl::GLBufferObject &indexBuf);
protected:
	virtual std::string getVshPath(){ return "shader/test1.vsh"; };
	virtual std::string getFshPath(){ return "shader/test1.fsh"; };
	virtual void onPreLink();
	virtual void onPostLink();
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

