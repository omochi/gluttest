#ifdef GL_ES

#else
# define lowp
#endif

varying lowp vec4 color;

void main(){
	gl_FragColor = color;
}