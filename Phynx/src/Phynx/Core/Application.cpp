#include "pxpch.h"
#include "Application.h"
#include "Logging/Log.h"

// Application with no override will provide an example in this code
// using a few of the features and typical usage
#include <glad/glad.h>

struct Vertex
{
	float pos[3];
	float col[4];
};


namespace PX {

	Application::Application()
	{
		PX_LOG_INIT;
		PX_CORE_INFO("Started Application instance and logging");
		m_pInstance = this;
	}

	void Application::Start()
	{
		WindowCreateStruct data = {};
		data.WindowName = "Phynx Engine";
		data.Width = 1280;
		data.Height = 720;
		
		CreateApplicationWindow(data);
		

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
		vao = VertexArray::Create();

		vbo = VertexBuffer::Create(sizeof(vertices), vertices);

		VertexElement elements[] = {
			{3, DataType::FLOAT, false, "Pos"},
			{4, DataType::FLOAT, false, "Col"}
		};

		LayoutData layout;
		layout.PushElement(elements[0]);
		layout.PushElement(elements[1]);

		vbo->ApplyLayout(layout);

		ibo = IndexBuffer::Create(sizeof(indices), indices);


		// Create the shaders
		const char* vs = R"(
			#version 450 core
			
			layout (location = 0) in vec3 pos;
			layout (location = 1) in vec4 i_col;

			out vec4 a_col;			

			void main()
			{
				a_col = i_col;
				gl_Position = vec4(pos, 1.f);
			}
			
		)";

		const char* fs = R"(
			#version 450 core
			
			out vec4 o_col;
			in vec4 a_col;
			
			void main()
			{
				o_col = a_col;
			}
			
		)";

		shader = Shader::Create(vs, fs);
	}

	void Application::OnUpdate()
	{
		Renderer::Clear(0.3f, 0.9f, 0.6f, 1.f);

		vao->Bind();
		shader->Bind();
		Renderer::DrawIndexed(3);
	}

	void Application::OnRender()
	{

	}

	void Application::Shutdown()
	{

	}

	void Application::Run()
	{
		// Create

		auto& layers = m_LayerManager.GetLayers();

		for (auto layer : m_LayerManager.GetLayers())
			layer->OnCreate();

		while (m_Window->IsRunning())
		{
			/*OnUpdate();
			OnRender();*/

			for (int i = 0; i < layers.size(); ++i)
				layers[i]->OnUpdate();

			for (int i = 0; i < layers.size(); ++i)
				layers[i]->OnRender();

			m_Window->Update();
		}

		for (auto layer : m_LayerManager.GetLayers())
			layer->OnDestroy();
	}

	Application* Application::GetApplicationInstance()
	{
		return m_pInstance;
	}

	Shared<Window> Application::GetApplicationWindow()
	{
		return m_Window;
	}

	void Application::CreateApplicationWindow(WindowCreateStruct& data)
	{
		m_Window = Window::Create(data);


		// Call the init function here
		Renderer::Init();
	}


}