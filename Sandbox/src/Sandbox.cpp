#include "Sandbox.h"


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

	PX::Element elements[] = {
			{3, PX::DataType::FLOAT, false, "Pos"},
			{4, PX::DataType::FLOAT, false, "Col"}
	};

	PX::LayoutData layout;
	layout.PushElement(elements[0]);
	layout.PushElement(elements[1]);

	vbo->ApplyLayout(layout);

	ibo = PX::IndexBuffer::Create(sizeof(indices), indices);
	shader = PX::Shader::CreateFromFile("assets/shaders/vert.shader", "assets/shaders/frag.shader");
}

void Sandbox::Update()
{
	PX::Renderer::Clear(0.3f, 0.7f, 0.9f, 1.f);

	vao->Bind();
	shader->Bind();

	PX::Renderer::DrawIndexed(3);
}
