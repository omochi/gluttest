#include <OMGL/OMGL.h>

class Test1Shader : public omgl::GLProgram{
public:
	enum{
		ATTR_POS,
		ATTR_COUNT
	};
	GLint attrs[ATTR_COUNT];
	enum{
		UNI_MODEL,
		UNI_VIEWING,
		UNI_PROJECTION,
		UNI_COUNT
	};
	GLint unis[UNI_COUNT];


	mat viewing;
	mat projection;

protected:
	virtual std::string getVshPath(){ return "shader/test1.vsh"; };
	virtual std::string getFshPath(){ return "shader/test1.fsh"; };
	virtual void onPreLink(){
		bindAttribLocation(ATTR_POS,"position");
	}
	virtual void onPostLink(){
		unis[UNI_MODEL] = getUniformLocation("model");
		unis[UNI_VIEWING] = getUniformLocation("viewing");
		unis[UNI_PROJECTION] = getUniformLocation("projection");
	}
};