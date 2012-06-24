#include "Application.h"

#include <gl/glut.h>
#include <glm/glm.hpp>
#include <Engine/Engine.h>

#include "platform.h"
#include "TestApp.h"

void Application::setFps(int fps){
	m_Fps =  fps;
}
int Application::getFrameMsec(){
	return 1000/m_Fps;
}
float Application::getFrameSec(){
	return 1.f/m_Fps;
}

void Application::onReshapeFunc(int w,int h){

	m_Engine->setViewport(Rect(0,0,w,h));

}
void Application::onTimerFunc(int v){
	uint beginTime = platform::getTimeMsec();

	float sec = (beginTime-m_PrevFrameBeginTime)/1000.f;
	//10フレ分ぐらいが限度

	//getTimeMSecの循環が起きた場合は負になる
	sec = glm::clamp(sec,0.f,getFrameSec()*10.f);

	m_Engine->update(sec);

	glutPostRedisplay();

	m_PrevFrameBeginTime = beginTime;

	uint endTime = platform::getTimeMsec();

	int sleepTime = glm::max(0,getFrameMsec() - static_cast<int>(endTime-beginTime));
	glutTimerFunc(sleepTime,timerFunc,0);
}
void Application::onIdleFunc(){
}
void Application::onDisplayFunc(){
	m_Engine->render();
	glutSwapBuffers();
	renderCount++;
}

void Application::initialize(int argc,char *argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1280,720);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(Application::displayFunc);
	glutReshapeFunc(Application::reshapeFunc);
	glutIdleFunc(Application::idleFunc);

	glutMouseFunc(Application::mouseFunc);
	glutMotionFunc(Application::motionFunc);
	glutPassiveMotionFunc(Application::passiveMotionFunc);

	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);

	m_Engine = new TestApp();

	updateFrameCount=0;
	renderCount=0;
	setFps(60);
	platform::initialize();
	m_Engine->initialize();

	m_PrevFrameBeginTime = platform::getTimeMsec();
	glutTimerFunc(0,Application::timerFunc,0);

}
void Application::finalize(){
	m_Engine->finalize();
	platform::finalize();

	SAFE_DELETE(m_Engine);
}

int Application::main(int argc,char *argv[]){
	initialize(argc,argv);
	glutMainLoop();
	finalize();
	return 0;
}

Application &Application::instance(){
	static Application instance;
	return instance;
}

void Application::reshapeFunc(int w, int h){
	instance().onReshapeFunc(w,h);
}
void Application::timerFunc(int value){
	instance().onTimerFunc(value);
}
void Application::idleFunc(){
	instance().onIdleFunc();
}
void Application::displayFunc(){
	instance().onDisplayFunc();
}



void Application::mouseFunc(int button, int state, int x, int y){
	instance().m_Engine->input().onGLUTMouseFunc(button,state,x,y);
}
void Application::motionFunc(int x,int y){
	instance().m_Engine->input().onGLUTMotionFunc(x,y);
}
void Application::passiveMotionFunc(int x,int y){
	instance().m_Engine->input().onGLUTPassiveMotionFunc(x,y);
}