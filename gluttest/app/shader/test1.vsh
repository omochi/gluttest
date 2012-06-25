#ifdef GL_ES

#else
# define lowp
#endif


attribute vec3 pos;

uniform mat4 model;
uniform mat4 viewing;
uniform mat4 projection;

uniform vec4 color;

void main(){
	gl_Position = projection * viewing * model * vec4(pos,1.0);
}