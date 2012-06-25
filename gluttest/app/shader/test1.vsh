#ifdef GL_ES

#else
# define lowp
#endif


attribute vec4 pos;

varying lowp vec4 color;

uniform mat4 model;
uniform mat4 viewing;
uniform mat4 projection;

void main(){
	gl_Position = projection * viewing * model * pos;
}