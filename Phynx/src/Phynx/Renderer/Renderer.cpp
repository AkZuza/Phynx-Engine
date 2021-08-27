#include "pxpch.h"
#include "Renderer.h"
#include "API/OpenGL/OpenGLRenderer.h"

namespace PX {

	void Renderer::Init()
	{
		m_RendererAPI = Shared<Renderer>(new OpenGLRenderer());
	}

}