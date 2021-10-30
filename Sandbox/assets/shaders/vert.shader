#version 450 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec4 i_col;

out vec4 a_col;

void main()
{
	a_col = i_col;
	gl_Position = vec4(pos, 1.f);
}
