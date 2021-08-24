#include "Sandbox.h"
#include <fstream>

// supppppeerrrrrr temporary and just for fixing gpu usage stuff
#include <glad/glad.h>

PX::Application* PX::CreateApplicationInstance()
{
	return new Sandbox();
}

uint32_t loc = 0;

void Sandbox::Start()
{
	PX::WindowCreateStruct data;
	data.Width = 1280;
	data.Height = 720;
	data.WindowName = "Sandbox";

	CreateApplicationWindow(data);

	struct Vertex
	{
		float pos[3];
		float col[4];
	};

	// initialize
	Vertex vertices[] = {
		{-0.5f, -0.5f, 1.f,    1.f, 0.f, 0.f, 1.f},
		{ 0.5f, -0.5f, 1.f,    0.f, 1.f, 0.f, 1.f},
		{ 0.0f,  0.5f, 1.f,    0.f, 0.f, 1.f, 1.f},
	};

	uint32_t indices[] = {
		0, 1, 2
	};

	// Create buffers
	vao = PX::VertexArray::Create();

	vbo = PX::VertexBuffer::Create(sizeof(vertices), vertices);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(Vertex), (void*)offsetof(Vertex, pos));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, false, sizeof(Vertex), (void*)offsetof(Vertex, col));

	ibo = PX::IndexBuffer::Create(sizeof(indices), indices);
	std::ifstream v("assets/shaders/vert.shader");
	std::ifstream f("assets/shaders/frag.shader");
	shader = PX::Shader::Create(v, f);
}

void Sandbox::Update()
{
	glClearColor(0.4f, 0.9f, 0.3f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);

	vao->Bind();
	shader->Bind();

	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
}
