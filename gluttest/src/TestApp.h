#pragma once

#include <Engine/Engine.h>

#include "Shader/Test1.h"

class TestApp : public engine::Engine{
private:

	omgl::ParseCamera cam;
	omgl::Cube cube;

	omgl::Cylinder cyl;
	omgl::Sphere sph;
	omgl::Cone cone;
	omgl::Circle cir;


	omgl::ArrowXYZ uiArw;

	float camYaw;
	float camPitch;

	Test1Shader sh;

	virtual void render();

protected:
	virtual void onInitialize();
	virtual void onFinalize();
	virtual void onUpdate(float sec);
};