#include "pxpch.h"
#include "Renderer.h"
#include "API/OpenGL/OpenGLRenderer.h"

#include "Renderer2D.h"

namespace PX {

	void Renderer::Init()
	{
		m_RendererAPI = Shared<Renderer>(new OpenGLRenderer());
		Renderer2D::Init();
	}

	void Renderer::Draw(uint32_t count, Shared<VertexBuffer> buffer, Shared<Shader> shader)
	{
		buffer->Bind();
		shader->Bind();
		Draw(count);
	}

	void Renderer::DrawIndexed(uint32_t count, Shared<VertexArray> varray, Shared<Shader> shader)
	{
		varray->Bind();
		shader->Bind();
		DrawIndexed(count);
	}

}