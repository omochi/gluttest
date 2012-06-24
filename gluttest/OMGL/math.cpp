#include "math.h"

namespace omgl{
	mat lookAt(vec3 f,vec3 up){
		mat m(1);
		vec3 s = glm::cross(up,f);
		vec3 y = glm::cross(f,s);
		m[0][0] = s[0];
		m[0][1] = s[1];
		m[0][2] = s[2];

		m[1][0] = y[0];
		m[1][1] = y[1];
		m[1][2] = y[2];

		m[2][0] = f[0];
		m[2][1] = f[1];
		m[2][2] = f[2];
		return m;
	}
	mat lookAt(vec3 eye,vec3 at,vec3 up){
		vec3 f = glm::normalize(at-eye);
		return lookAt(f,up);
	}
}