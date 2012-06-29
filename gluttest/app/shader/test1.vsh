#ifdef GL_ES

#else
# define lowp
#endif

attribute vec3 aPos;
attribute vec3 aNormal;

uniform mat4 uModel;
uniform mat4 uViewing;
uniform mat4 uProjection;

uniform mat3 uModelNormal;

uniform vec3 uAmbient;
uniform vec3 uDirection;
uniform vec3 uDirectionColor;

varying vec3 vLightWeight;

void main(){
	gl_Position = uProjection * uViewing * uModel * vec4(aPos,1.0);
	
	vec3 normal = normalize(uModelNormal * aNormal);
	float dirWeight = max(0.0,dot(normal,- normalize(uDirection) ));
	vLightWeight = uAmbient + uDirectionColor * dirWeight;
}