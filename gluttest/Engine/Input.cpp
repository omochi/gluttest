#include "Input.h"
namespace engine{

	void Input::clearAllKey(){
		for(int i=0;i<ARRAY_SIZE(m_KeyPressed);i++)m_KeyPressed[i]=false;
	}
	void Input::clearMouse(){
		setMousePos(0,0);
		m_MousePosPrev = m_MousePos;
		m_MouseVel = vec3(0,0,0);
		for(int i=0;i<ARRAY_SIZE(m_MousePressed);i++)m_MousePressed[i]=false;
	}
	bool Input::isKeyPressed(KeyCode key)const{
		return m_KeyPressCount[key]>0;
	}
	bool Input::isOnKeyPressed(KeyCode key)const{
		return m_KeyPressCount[key]==1;
	}

	vec3 Input::getMousePos()const{
		return m_MousePos;
	}
	vec3 Input::getMouseVel() const{
		return m_MouseVel;
	}
	bool Input::isMousePressed(MouseButton btn)const{
		return m_MousePressed[btn];
	}

	void Input::update(float sec){
#ifdef _WIN32
		ASSERT(GetKeyboardState(m_KeyPressed)!=0);
#endif
		 
		for(int i=0;i<ARRAY_SIZE(m_KeyPressCount);i++){
			if(m_KeyPressed[i] & 0x80){
				m_KeyPressCount[i] ++;
				if(m_KeyPressCount[i] > 12)m_KeyPressCount[i] -= 10;
			}else{
				m_KeyPressCount[i] = 0;
			}
		}

		m_MouseVel = m_MousePos - m_MousePosPrev;
		m_MouseVel /= sec;

		m_MousePosPrev = m_MousePos;
	}

	void Input::onGLUTMouseFunc(int button, int state, int x, int y){
		if(button==GLUT_LEFT_BUTTON){
			if(state==GLUT_DOWN){
				m_MousePressed[MouseButtonLeft] = true;
			}else if(state==GLUT_UP){
				m_MousePressed[MouseButtonLeft] = false;
			}
		}else if(button==GLUT_RIGHT_BUTTON){
			if(state==GLUT_DOWN){
				m_MousePressed[MouseButtonRight] = true;
			}else if(state==GLUT_UP){
				m_MousePressed[MouseButtonRight] = false;
			}
		}
		setMousePos(x,y);
	}
	void Input::onGLUTMotionFunc(int x,int y){
		setMousePos(x,y);
	}

	void Input::onGLUTPassiveMotionFunc(int x,int y){
		setMousePos(x,y);
		m_MousePressed[MouseButtonLeft] = false;
		m_MousePressed[MouseButtonRight] = false;
	}

	void Input::setMousePos(int x,int y){

		m_MousePos.x = static_cast<float>(x);
		m_MousePos.y = static_cast<float>(y);
		m_MousePos.z = 0.f;
	}

	/*
	void Input::setGLUTAsciiDown(unsigned char k){
		KeyCode code = getKeyCodeFromGLUTKey(k);
		if(code!=KeyCodeNull){
			setKeyDown(code);
		}
	}
	void Input::setGLUTAsciiUp(unsigned char k){
		KeyCode code = getKeyCodeFromGLUTKey(k);
		if(code!=KeyCodeNull){
			setKeyUp(code);
		}
	}

	void Input::setKeyDown(KeyCode key){
		ASSERT(key!=KeyCodeNull);
		m_KeyPressed[key] = true;
	}
	void Input::setKeyUp(KeyCode key){
		ASSERT(key!=KeyCodeNull);
		m_KeyPressed[key] = false;
	}
	*/
}