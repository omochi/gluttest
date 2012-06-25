﻿#include "TestApp.h"

#include "Shader/Test1.h"

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

	cyl.setPos(2,0,0);
	//scene().addChild(&cyl);

	cone.setPos(-2,0,0);
	//scene().addChild(&cone);

	sph.setPos(0,2,0);
	//scene().addChild(&sph);

	cir.setPos(2,2,0);
	//scene().addChild(&cir);

	if(!sh.load()){
		FAIL("");
	}

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
		omgl::DefaultRenderer *r = dynamic_cast<omgl::DefaultRenderer *>(&renderer()); 
		if(r){
			r->m_DispTriangle = ! r->m_DispTriangle;
		}
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

void TestApp::render(){

	glViewport(viewport().left(),viewport().top(),
		viewport().width(),viewport().height());

	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	omgl::Camera *cam = scene().getMainCamera();
	if(cam!=NULL){
		cam->m_Width = viewport().width();
		cam->m_Height = viewport().height();
		
		//dynamic_cast<omgl::DefaultRenderer &>(renderer()).m_DispTriangle=true;
		//renderer().renderScene(&scene());

		sh.renderScene(&scene());
	}
	
	
	glClear(GL_DEPTH_BUFFER_BIT);
	m_UICamera.m_Width = viewport().width();
	m_UICamera.m_Height = viewport().height();
	//m_UIRenderer.renderScene(&m_UIScene);
	
	sh.renderScene(&m_UIScene);

	glutSwapBuffers();
	
}