#pragma once

#include <Engine/Engine.h>

class TestApp : public engine::Engine{
private:

	omgl::ParseCamera cam;
	omgl::Cube cube;
	omgl::ArrowXYZ uiArw;

	float camYaw;
	float camPitch;

protected:
	virtual void onInitialize();
	virtual void onFinalize();
	virtual void onUpdate(float sec);
};