#pragma once

#include <Engine/Engine.h>
#include <OMGL/ParseCamera.h>
#include <OMGL/OrthoCamera.h>
#include <OMGL/Prim/Square.h>
#include <OMGL/Prim/Cube.h>
#include <OMGL/Prim/Circle.h>
#include <OMGL/Prim/Cylinder.h>
#include <OMGL/Prim/Cone.h>
#include <OMGL/Prim/ArrowXYZ.h>
#include <OMGL/Prim/Sphere.h>

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