#pragma once

#include "type.h"


namespace engine{
	class Engine;
}

class Application{
private:
	engine::Engine *m_Engine;

	int m_Fps;


	//int m_ViewportWidth;
	//int m_ViewportHeight;

	uint updateFrameCount;
	uint renderCount;
	uint m_PrevFrameBeginTime;

	Application(){};

	void setFps(int fps);
	int getFps();

	int getFrameMsec();
	float getFrameSec();

	void updateFrame(float sec);

	void initialize(int argc,char *argv[]);
	void finalize();

	void onDisplayFunc();
	void onReshapeFunc(int w,int h);
	void onTimerFunc(int v);
	void onIdleFunc();

	static void displayFunc(void);
	static void reshapeFunc(int w, int h);
	static void timerFunc(int value);
	static void idleFunc();

//	static void keyboardFunc(unsigned char key,int x,int y);
//	static void keyboardUpFunc(unsigned char key,int x,int y);
//	static void entryFunc(int val);
	static void mouseFunc(int button, int state, int x, int y);
	static void motionFunc(int x,int y);
	static void passiveMotionFunc(int x,int y);
	
public:	
	static Application &instance();
	int main(int argc,char *argv[]);
};