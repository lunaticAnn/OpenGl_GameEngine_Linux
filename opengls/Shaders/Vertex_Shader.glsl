//vertex shader
#version 430 core 
layout(location = 0) in vec3 in_position;
layout(location = 1) in vec4 in_color;


uniform mat4 model_matrix, projection_matrix, view_matrix;

out vec4 color;

void main(){
	color = in_color;
	gl_Position = projection_matrix * view_matrix *
		model_matrix * vec4(in_position, 1);
}