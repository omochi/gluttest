#pragma once
#include "common.h"

namespace omgl{
	class Transform{
	private:
		vec3 m_Pos;
		quat m_Rot;
		vec3 m_Scale;
	public:
		Transform(){
			m_Pos=vec3(0,0,0);
			m_Rot=quat();
			m_Scale=vec3(1,1,1);
			//setRotLookAt(vec3(0,0,-1),vec3(0,1,0));
		}
		const vec3 &getPos() const;

		void setPos(const vec3 &pos);
		void setPos(float x,float y,float z);

		const quat &getRotQuat() const;
		//一意にならない
		//vec3 getRotEular() const;
		mat getRotMat() const;
		void setRotQuat(const quat &quat);
		void setRotMat(const mat &m);

		void setRotEular(const vec3 &angles);
		void setRotEular(float x,float y,float z);

		void setRotLookAt(const vec3 &target,const vec3 &up);
		const vec3 &getScale() const;
		void setScale(float s);
		void setScale(const vec3 &scale);
		void setScale(float x,float y,float z);
		//変更キャッシュとかは後で
		const mat getTransform() const;
		void setTransform(const mat &transform);
		void setTransform(const Transform &transform);
	};
}
