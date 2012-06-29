#ifdef GL_ES

#else
# define lowp
#endif

attribute vec3 aPos;
attribute vec3 aNormal;

uniform mat4 uModel;
uniform mat4 uViewing;
uniform mat4 uProjection;

uniform mat3 uNormalMatrix;

uniform vec3 uAmbient;
uniform vec3 uDirection;
uniform vec3 uDirectionColor;

varying vec3 vLightWeight;

void main(){
	gl_Position = uProjection * uViewing * uModel * vec4(aPos,1.0);
	
	//vec4 normal = uNormalMatrix * vec4(aNormal,1.0);
	//float dirWeight = max(0.0,dot(normal,uDirection));
	//vLightWeight = uAmbient + uDirectionColor * dirWeight;
}