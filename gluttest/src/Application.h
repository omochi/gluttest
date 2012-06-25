#pragma once
#include <OMBase/OMBase.h>

#ifdef _WIN32
#include <MMSystem.h>
#endif

#include <Engine/Engine.h>

class Application{
private:
	engine::Engine *m_Engine;


	int m_Fps;

	uint m_PrevFrameBeginTime;

	Application(){};

	void setFps(int fps);
	int getFps();

	int getFrameMsec();
	float getFrameSec();

	void updateFrame(float sec);

	bool initialize(int argc,char *argv[]);
	void finalize();

	void onDisplayFunc();
	void onReshapeFunc(int w,int h);
	void onTimerFunc(int v);
	void onIdleFunc();

	static void displayFunc(void);
	static void reshapeFunc(int w, int h);
	static void timerFunc(int value);
	static void idleFunc();

	static void mouseFunc(int button, int state, int x, int y);
	static void motionFunc(int x,int y);
	static void passiveMotionFunc(int x,int y);

	void exceptionHandler(const std::exception &e);
	
public:	
	static Application &instance();
	int main(int argc,char *argv[]);
};