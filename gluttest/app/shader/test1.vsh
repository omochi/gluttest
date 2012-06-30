#ifdef GL_ES

#else
# define lowp
#endif

attribute vec3 aPos;
attribute vec3 aNormal;

uniform mat4 uModel;
uniform mat4 uViewing;
uniform mat4 uProjection;

uniform bool uNormalEnabled;
uniform mat3 uModelNormal;

varying vec3 vNormal;

void main(){
	gl_Position = uProjection * uViewing * uModel * vec4(aPos,1.0);
	if(uNormalEnabled){
		vNormal = uModelNormal * aNormal;
	}
}