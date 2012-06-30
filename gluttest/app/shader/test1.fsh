#ifdef GL_ES

#else
# define lowp
#endif

uniform vec4 uColor;

uniform bool uNormalEnabled;
uniform bool uNormalColorView;

varying vec3 vNormal;
uniform vec3 uAmbient;
uniform vec3 uDirection;
uniform vec3 uDirectionColor;
void main(){
	if(uNormalEnabled){
	
		vec3 normal = normalize(vNormal);
		float dirWeight = max(0.0,dot(normal,-uDirection));
		float lightWeight = uAmbient + uDirectionColor * dirWeight;
		
		if(uNormalColorView){
			gl_FragColor = vec4(normal/2.0 + vec3(0.5,0.5,0.5),1.0);	
		}else{
			gl_FragColor = vec4(uColor.xyz *  lightWeight , uColor.w);
		}
	}else{
		gl_FragColor = uColor;
	}
}