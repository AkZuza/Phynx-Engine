#pragma once
#include "Window.h"
#include "../Renderer/VertexArray.h"
#include "../Renderer/Buffer.h"
#include "../Renderer/Shader.h"
#include "../Event/Event.h"
#include "../Renderer/Renderer.h"
#include "../Renderer/Layer.h"
#include "../Renderer/LayerManager.h"

namespace PX {

	class Application
	{
	public:
		Application();
		virtual void Start();
		virtual void Shutdown();
		void Run();

		// Methods to interface with Layer Manager
		void PushLayer(Layer* layer) { m_LayerManager.PushLayer(layer); }
		void PushOverlayLayer(Layer* layer) { m_LayerManager.PushOverlayLayer(layer); }
		void PopLayer() { m_LayerManager.PopLayer(); }
		void PopOverlayLayer() { m_LayerManager.PopOverlayLayer(); }

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
		virtual void OnUpdate();
		virtual void OnRender();

	private:
		static inline Application* m_pInstance = nullptr;
		static inline Shared<Window> m_Window;

		LayerManager m_LayerManager;

		// Example default program
		Shared<VertexBuffer> vbo;
		Shared<IndexBuffer> ibo;
		Shared<VertexArray> vao;
		Shared<Shader> shader;
	};

	// To be defined by the final application
	Application* CreateApplicationInstance();
}