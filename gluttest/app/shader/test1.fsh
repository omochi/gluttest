#ifdef GL_ES

#else
# define lowp
#endif

uniform vec4 uColor;

uniform bool uNormalEnabled;
varying vec3 vLightWeight;

void main(){
	if(uNormalEnabled){
		gl_FragColor = vec4(uColor.xyz *  vLightWeight , uColor.w);
	}else{
		gl_FragColor = uColor;
	}
}