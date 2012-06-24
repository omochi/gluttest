#include "TestApp.h"
#include<glm/ext.hpp>

void TestApp::onInitialize(){

	uiArw.setScale(100,100,100);
	UIScene().addChild(&uiArw);

	cam.m_Fovy = 60.f;
	cam.m_Near = 0.1f;
	cam.m_Far = 1000.f;
	cam.setPos(vec3(0,0,5.f));
	scene().addMainCamera(&cam);
	
	camYaw=M_PI;
	camPitch=0;

	cube.setPos(0,0,0.f);
	scene().addChild(&cube);


}

void TestApp::onFinalize(){

}


void TestApp::onUpdate(float sec){
	quat q = cube.getRotQuat();
	quat spin = glm::rotate(q,180.f*sec,vec3(0,1,0));
	cube.setRotQuat(spin);

	omgl::Camera *cam = scene().getMainCamera();
	
	std::string str;

	if(input().isOnKeyPressed(engine::KeyCodeP)){
		str = glm::to_string(cam->getProjection());
		printf("%s\n",str.c_str());
	}
	if(input().isOnKeyPressed(engine::KeyCodeL)){
		renderer().m_DispTriangle = ! renderer().m_DispTriangle;
	}


	vec3 mouse = transWindowToViewport(input().getMousePos());
	vec3 vel = input().getMouseVel();

	if(input().isMousePressed(engine::MouseButtonRight)){
		camYaw = cycleClamp( camYaw - M_2PI*vel.x*sec/2000.f ,-M_PI,M_PI);
		camPitch = glm::clamp(camPitch + M_2PI*vel.y*sec/2000.f,-M_PI_2,M_PI_2);
	}
	cam->setRotEular(camPitch,camYaw,0.f);

	vec3 move(0.f,0.f,0.f);
	if(input().isKeyPressed(engine::KeyCodeW)){
		move.z += 1.f;
	}
	if(input().isKeyPressed(engine::KeyCodeS)){
		move.z -= 1.f;
	}
	if(input().isKeyPressed(engine::KeyCodeA)){
		move.x += 1.f;
	}
	if(input().isKeyPressed(engine::KeyCodeD)){
		move.x -= 1.f;
	}
	if(input().isKeyPressed(engine::KeyCodeSpace)){
		move.y += 1.f;
	}
	if(input().isKeyPressed(engine::KeyCodeLControl)){
		move.y -= 1.f;
	}

	
	mat rot = glm::eulerAngleYXZ(camYaw,0.f,0.f);
	
	move = vec3(glm::mul(rot,vec4(move,1.f)));

	cam->setPos(cam->getPos()+move*sec);

	mat mi(1);


	mi = glm::scale(-1.f,1.f,-1.f) * cam->getViewing();

	uiArw.setRotMat(mi);

	float ux = viewport().right() -120.f -  viewport().center().x;
	float uy = - (viewport().top() +120.f  - viewport().center().y);
	uiArw.setPos(ux,uy,0);

}