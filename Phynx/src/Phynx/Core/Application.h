#pragma once
#include "Window.h"
#include "../Renderer/VertexArray.h"
#include "../Renderer/Buffer.h"
#include "../Renderer/Shader.h"
#include "../Event/Event.h"
#include "../Renderer/Renderer.h"

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


		/// <summary>
		/// Creates a window.
		/// Despite the name, it does more than create the window.
		/// it sets the API to use, prepares other functions such as
		/// logging, the renderer api implementation.
		/// API specific changes cannot be done after calling this function
		/// </summary>
		/// <param name="data">The window creation data</param>
		static void CreateApplicationWindow(WindowCreateStruct& data);

		virtual void OnEvent(Event& event) {}

	protected:
		virtual void Update();
		virtual void Render();

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