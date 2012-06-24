#include "Transform.h"
namespace omgl{
	const vec3 &Transform::getPos() const{
		return m_Pos;
	}
	void Transform::setPos(const vec3 &pos){
		m_Pos = pos;
	}
	void Transform::setPos(float x,float y,float z){
		setPos(vec3(x,y,z));
	}
	const quat &Transform::getRotQuat() const{
		return m_Rot;
	}
	
	//vec3 Transform::getRotEular() const{
	//	return glm::eulerAngles(m_Rot);
	//}

	mat Transform::getRotMat() const{
		return glm::mat4_cast(m_Rot);
	}

	void Transform::setRotQuat(const quat &quat){
		m_Rot = quat;
	}
	void Transform::setRotMat(const mat &m){
		m_Rot = glm::quat_cast(m);
	}
	void Transform::setRotEular(const vec3 &angles){
		setRotEular(angles.x,angles.y,angles.z);
	}
	void Transform::setRotEular(float x,float y,float z){
		mat m = glm::eulerAngleYXZ(y,x,z);
		m_Rot = glm::quat_cast(m);
	}
	void Transform::setRotLookAt(const vec3 &target,const vec3 &up){
		mat m = omgl::lookAt(getPos(),target,up);
		m_Rot = glm::quat_cast(m);
	}
	const vec3 &Transform::getScale() const{
		return m_Scale;
	}
	void Transform::setScale(float s){
		setScale(s,s,s);
	}
	void Transform::setScale(const vec3 &scale){
		m_Scale=scale;
	}
	void Transform::setScale(float x,float y,float z){
		m_Scale.x = x;
		m_Scale.y = y;
		m_Scale.z = z;
	}
	const mat Transform::getTransform() const{
		mat m(1.f);
		
		
		
		m = glm::translate(m,m_Pos);
		mat rot = glm::mat4_cast(m_Rot);
		m = glm::mul(m,rot);
		m = glm::scale(m,m_Scale);

		
		return m;
	}
	void Transform::setTransform(const mat &m){
		//Ç†Ç¡ÇƒÇÈÇÃÇ©ÇµÇÁÅH
		Transform t;
		t.m_Pos = vec3(glm::column(m,3));
		t.m_Rot = glm::quat_cast(m);
		
		mat base(1.f);
		mat rot = glm::mat4_cast(m_Rot);
		base = glm::mul(rot,base);

		t.m_Scale = vec3(
			glm::dot(glm::column(base,0),glm::column(m,0)),
			glm::dot(glm::column(base,1),glm::column(m,1)),
			glm::dot(glm::column(base,2),glm::column(m,2))
		);
		setTransform(t);
	}
	void Transform::setTransform(const Transform &src){
		m_Pos = src.m_Pos;
		m_Rot = src.m_Rot;
		m_Scale = src.m_Scale;
	}
}