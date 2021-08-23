#pragma once
#include "Window.h"
#include "../Renderer/VertexArray.h"
#include "../Renderer/Buffer.h"
#include "../Renderer/Shader.h"

namespace PX {

	class Application
	{
	public:
		Application();
		virtual void Start();
		virtual void Shutdown();
		void Run();

		static Application* GetApplicationInstance();
		static Shared<Window> GetApplicationWindow();
		static void CreateApplicationWindow(WindowCreateStruct& data);

	protected:
		virtual void Update();

	private:
		static inline Application* m_pInstance = nullptr;
		static inline Shared<Window> m_Window;

		// Example default program
		Shared<VertexBuffer> vbo;
		Shared<IndexBuffer> ibo;
		Shared<VertexArray> vao;
		Shared<Shader> shader;
	};

	// To be defined by the final application
	Application* CreateApplicationInstance();
}