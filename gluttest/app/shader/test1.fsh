#ifdef GL_ES

#else
# define lowp
#endif

uniform vec4 color;

void main(){
	gl_FragColor = color;
}