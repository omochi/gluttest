#include "Application.h"

#include <Engine/Engine.h>

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

	uint beginTime = timeGetTime();
	float sec = (beginTime-m_PrevFrameBeginTime)/1000.f;
	//スキップは10フレ分ぐらいが限度、getTimeMSecの循環が起きた場合は負になる
	sec = glm::clamp(sec,0.f,getFrameSec()*10.f);

	try{
		m_Engine->update(sec);
	}catch(const std::exception &e){
		exceptionHandler(e);
	}
	glutPostRedisplay();

	m_PrevFrameBeginTime = beginTime;
	uint endTime = timeGetTime();
	int sleepTime = glm::max(0,getFrameMsec() - static_cast<int>(endTime-beginTime));
	glutTimerFunc(sleepTime,timerFunc,0);

}
void Application::onIdleFunc(){
}
void Application::onDisplayFunc(){

	try{
		m_Engine->render();
	}catch(const std::exception &e){
		exceptionHandler(e);
	}

}

bool Application::initialize(int argc,char *argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1280,720);
	glutCreateWindow(argv[0]);

	GLenum err;
	err = glewInit();
	if (err != GLEW_OK){
		fprintf(stderr,"glewInit:%s\n",glewGetErrorString(err));
		return false;
	}

	printf("OpenGL version = %s\n",glGetString(GL_VERSION));
	if(!glewIsSupported("GL_VERSION_3_0")){
		fprintf(stderr,"OpenGL 3.0 is not supported\n");
		return false ;
	}

	glutDisplayFunc(Application::displayFunc);
	glutReshapeFunc(Application::reshapeFunc);
	glutIdleFunc(Application::idleFunc);
	glutMouseFunc(Application::mouseFunc);
	glutMotionFunc(Application::motionFunc);
	glutPassiveMotionFunc(Application::passiveMotionFunc);
	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
	glutTimerFunc(0,Application::timerFunc,0);

	timeBeginPeriod(1);

	setFps(60);
	m_PrevFrameBeginTime = timeGetTime();

	m_Engine = new TestApp();
	m_Engine->initialize();

	return true;
}
void Application::finalize(){
	m_Engine->finalize();

	timeEndPeriod(1);

	SAFE_DELETE(m_Engine);
}

void Application::exceptionHandler(const std::exception &e){

	char buf[1000];
	base::snprintf(buf,sizeof(buf),"exception:%s\n",e.what());

	fprintf(stderr,buf);
	OutputDebugString(buf);

	exit(EXIT_FAILURE);
}

int Application::main(int argc,char *argv[]){
	bool ok = initialize(argc,argv);
	if(ok){
		glutMainLoop();
	}
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