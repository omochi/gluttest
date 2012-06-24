#pragma once

#include <src/util.h>
#include <src/type.h>

#include <gl/glut.h>

#ifdef _WIN32
#include<Winuser.h>
#endif

namespace engine{
	enum MouseButton{
		MouseButtonLeft = 0,
		MouseButtonRight = 1
	};
	enum KeyCode{
		KeyCodeA = 0x41,
		KeyCodeB = 0x42,
		KeyCodeC = 0x43,
		KeyCodeD = 0x44,
		KeyCodeE = 0x45,
		KeyCodeF = 0x46,
		KeyCodeG = 0x47,
		KeyCodeH = 0x48,
		KeyCodeI = 0x49,
		KeyCodeJ = 0x4a,
		KeyCodeK = 0x4b,
		KeyCodeL = 0x4c,
		KeyCodeM = 0x4d,
		KeyCodeN = 0x4e,
		KeyCodeO = 0x4f,
		KeyCodeP = 0x50,
		KeyCodeQ = 0x51,
		KeyCodeR = 0x52,
		KeyCodeS = 0x53,
		KeyCodeT = 0x54,
		KeyCodeU = 0x55,
		KeyCodeV = 0x56,
		KeyCodeW = 0x57,
		KeyCodeX = 0x58,
		KeyCodeY = 0x59,
		KeyCodeZ = 0x5a,
		KeyCodeSpace = VK_SPACE,
		KeyCodeLShift = VK_LSHIFT,
		KeyCodeRShift = VK_RSHIFT,
		KeyCodeLControl = VK_LCONTROL,
		KeyCodeRControl = VK_RCONTROL,
		KeyCodeLMenu = VK_LMENU,
		KeyCodeRMenu = VK_RMENU
	};
	class Input{
	private:

		uchar m_KeyPressed[256];
		uchar m_KeyPressCount[256];

		//float m_MouseX;
		//float m_MouseY;
		vec3 m_MousePos;
		bool m_MousePressed[3];

		vec3 m_MousePosPrev;
		vec3 m_MouseVel;

	public:

		Input(){
			clearAllKey();
			clearMouse();			
		}
		void clearAllKey();
		void clearMouse();
		bool isKeyPressed(KeyCode key) const;
		bool isOnKeyPressed(KeyCode key)const;
		
		vec3 getMousePos()const;
		vec3 getMouseVel()const;
		bool isMousePressed(MouseButton btn)const;

		void setMousePos(int x,int y);

		void update(float sec);

		void onGLUTMouseFunc(int button, int state, int x, int y);
		void onGLUTMotionFunc(int x,int y);
		void onGLUTPassiveMotionFunc(int x,int y);


		//void setGLUTAsciiDown(unsigned char k);
		//void setGLUTAsciiUp(unsigned char k);

		//void setKeyDown(KeyCode key);
		//void setKeyUp(KeyCode key);

	};
}