#version 450 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec4 i_col;


uniform vec3 u_pos;
out vec4 a_col;

void main()
{
	a_col = i_col;
	gl_Position = vec4(pos + u_pos, 1.f);
}
