#pragma once

#include "type.h"

template<class T> class tRect{
private:
	T m_Left;
	T m_Top;
	T m_Width;
	T m_Height;
public:


	tRect():
	m_Left(0),m_Top(0),m_Width(0),m_Height(0){}
	tRect(T l,T t,T w,T h):
	m_Left(l),m_Top(t),m_Width(w),m_Height(h){}


	vec2 tRect<T>::center() const{
		return vec2(m_Left+m_Width/2.f,m_Top+m_Height/2.f);
	}
	
	T tRect<T>::left() const{
		return m_Left;
	}
	T tRect<T>::top() const{
		return m_Top;
	}
	T tRect<T>::width() const{
		return m_Width;
	}
	T tRect<T>::height() const{
		return m_Height;
	}

	T tRect<T>::bottom() const{
		return m_Top+m_Height;
	}

	T tRect<T>::right() const{
		return m_Left+m_Width;
	}
};

typedef tRect<float> RectF;
typedef tRect<int> Rect;