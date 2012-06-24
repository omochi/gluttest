#pragma once

#include "OMGL.h"
#include <gl/glut.h>
namespace omgl{

	class Color{
	public:
		vec4 v;

		Color():v(1.f,1.f,1.f,1.f){}
		
		explicit Color(float r,float g,float b,float a):v(r,g,b,a){}
		explicit Color(float r,float g,float b):v(r,g,b,1.f){}
		
		//ìKìñÇ»êFÇ™ó~ÇµÇ¢
		explicit Color(int idx);

		const GLfloat *ptr() const;
	};

	const Color ColorRed(1,0,0);
	const Color ColorOrange(1,0.5f,0);
	const Color ColorYellow(1,1,0);
	const Color ColorGreen(0,1,0);
	const Color ColorCyan(0,1,1);
	const Color ColorBlue(0,0,1);
	const Color ColorPurple(1,0,1);
	const Color ColorWhite(1,1,1);
	const Color ColorGray(0.5f,0.5f,0.5f);
	const Color ColorBlack(0,0,0);

	const Color ColorList[]={
		ColorRed,		
		ColorOrange,	
		ColorYellow,
		ColorGreen,	
		ColorCyan,	
		ColorBlue,	
		ColorPurple,	
		ColorWhite,	
		ColorGray,	
		ColorBlack	
	};
	const int ColorListLen = ARRAY_SIZE(ColorList);
}