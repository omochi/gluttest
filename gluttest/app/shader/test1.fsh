#ifdef GL_ES

#else
# define lowp
#endif

uniform vec4 uColor;
varying vec3 vLightWeight;

void main(){
	gl_FragColor = vec4(uColor.xyz *  /*vLightWeight*/ 1.0 , uColor.w);
	
}