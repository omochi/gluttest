#pragma once

#include "common.h"

namespace omgl{

	/*
	class Color : public glm::vec4{
	public:

		Color(float r,float g,float b,float a):vec4(r,g,b,a){}
		Color(float r,float g,float b):vec4(r,g,b,1.f){}
		Color():vec4(1.f,1.f,1.f,1.f){}
		
		Color(const Color &s):vec4(s.x,s.y,s.z,s.w){}

		explicit Color(int idx);



	};
	*/

	typedef glm::vec4 Color;

	const Color ColorRed		(1.f,0.f,0.f,1.f);
	const Color ColorOrange	(1.f,0.5f,0.f,1.f);
	const Color ColorYellow	(1.f,1.f,0.f,1.f);
	const Color ColorGreen	(0.f,1.f,0.f,1.f);
	const Color ColorCyan	(0.f,1.f,1.f,1.f);
	const Color ColorBlue	(0.f,0.f,1.f,1.f);
	const Color ColorPurple	(1.f,0.f,1.f,1.f);
	const Color ColorWhite	(1.f,1.f,1.f,1.f);
	const Color ColorGray	(0.5f,0.5f,0.5f,1.f);
	const Color ColorBlack	(0.f,0.f,0.f,1.f);

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

	Color getColor(int idx);
}