﻿#pragma once

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
	omgl::ArrowXYZ arwXYZ;


	omgl::ArrowXYZ uiArw;

	float camYaw;
	float camPitch;

	Test1Shader sh;

	

	bool m_DebugLine;
	bool m_DebugNormal;
	bool m_NormalColorView;
	bool m_Model;
	bool m_Spin;

	float dirLightRotY;

protected:
	virtual void onInitialize();
	virtual void onFinalize();
	virtual void onUpdate(float sec);
	virtual void onRender();
	virtual void onProfileFps();
public:
};