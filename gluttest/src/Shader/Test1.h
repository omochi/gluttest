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
		UNI_NORMAL_ENABLED,
		UNI_NORMAL_COLOR_VIEW,
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

	
	std::vector<omgl::DebugLines> m_DebugLines;

	omgl::DebugLines m_DebugNormals;
	omgl::DebugLines m_DebugWires;

	void drawDebugLines(const omgl::DebugLines &line);
protected:
	virtual std::string getVshPath(){ return "shader/test1.vsh"; };
	virtual std::string getFshPath(){ return "shader/test1.fsh"; };
	virtual void onPreLink();
	virtual void onPostLink();
public:
	Test1Shader();

	bool m_DebugLineEnabled;
	bool m_DebugNormalEnabled;
	bool m_ModelEnabled;
	bool m_NormalEnabled;
	bool m_NormalColorView;

	virtual void renderScene(const omgl::Scene &scene);

	virtual bool addNode(omgl::SceneNode &n);
	virtual void removeNode(omgl::SceneNode &n);

	virtual void renderNodeImpl(const omgl::GLTriangles &n);
	virtual bool loadNodeImpl(omgl::GLTriangles &n);
	virtual void releaseNodeImpl(omgl::GLTriangles &n);

	omgl::DebugLines &addDebugLines(const omgl::DebugLines &line);

	void drawDebugLines(const std::vector<vec3> &vecs,const omgl::Color &col);
};

