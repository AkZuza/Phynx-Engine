#include "pxpch.h"
#include "Renderer2D.h"
#include "Renderer.h"

#include "Core/Core.h"
#include "VertexArray.h"
#include "Buffer.h"
#include "Shader.h"

namespace PX {

	struct RendererData {
		Shared<VertexArray> vao;
		Shared<VertexBuffer> vbo;
		Shared<IndexBuffer> ibo;
		Shared<Shader> shader;

		// pointers to data
		struct Vertex
		{
			float pos[3];
			float col[4];
		};

		inline static const uint32_t MaxVertices = 2048;
		inline static const uint32_t MaxIndices = 1024;

		Vertex vertices[MaxVertices] = {};
		uint32_t indices[MaxIndices] = {};

		Vertex* VertexPtrBegin = vertices;
		Vertex* VertexPtrCurr = vertices;

		uint32_t* IndexPtrBegin = indices;
		uint32_t* IndexPtrCurr = indices;

		uint32_t IndexValue = 0;

	} s_RendererData;

	void Renderer2D::Init()
	{
		s_RendererData.vao = VertexArray::Create();
		s_RendererData.vao->Bind();
		
		// Vertex Buffer
		s_RendererData.vbo = VertexBuffer::Create(
			sizeof(s_RendererData.vertices),
			s_RendererData.vertices,
			{ BufferAccess::DRAW, BufferUsage::DYNAMIC }
		);

		// Apply layout
		LayoutData layout;
		layout.PushElement({ 3, DataType::FLOAT, false, "pos" });
		layout.PushElement({ 4, DataType::FLOAT, false, "col" });

		s_RendererData.vbo->ApplyLayout(layout);

		s_RendererData.ibo = IndexBuffer::Create(
			sizeof(s_RendererData.indices),
			s_RendererData.indices,
			{ BufferAccess::DRAW, BufferUsage::DYNAMIC }
		);

		s_RendererData.vao->Unbind();
		s_RendererData.vbo->Unbind();
		s_RendererData.ibo->Unbind();

		// Create the shaders
		const char* vertex_source = R"(

			#version 450 core
			
			layout (location = 0) in vec3 in_pos;
			layout (location = 1) in vec4 in_col;
			
			out vec4 a_col;
			
			void main()
			{
				gl_Position = vec4(in_pos, 1.f);
				a_col = in_col;
			
			}
			
		)";

		const char* frag_source = R"(

			#version 450 core
			
			in vec4 a_col;
			out vec4 o_col;
			
			void main()
			{
				o_col = a_col;
			}
		)";

		s_RendererData.shader = Shader::Create(vertex_source, frag_source);

		s_RendererData.VertexPtrBegin = s_RendererData.vertices;
		s_RendererData.IndexPtrBegin = s_RendererData.indices;
	}



	// Draw calls
	void Renderer2D::Begin()
	{
		s_RendererData.VertexPtrCurr = s_RendererData.vertices;
		s_RendererData.IndexPtrCurr = s_RendererData.indices;
		s_RendererData.IndexValue = 0;
	}

	void Renderer2D::End()
	{

	}

	void Renderer2D::Flush()
	{
		uint32_t vsize = s_RendererData.VertexPtrCurr - s_RendererData.VertexPtrBegin;
		uint32_t isize = s_RendererData.IndexPtrCurr - s_RendererData.IndexPtrBegin;

		s_RendererData.vbo->Bind();
		s_RendererData.ibo->Bind();
		s_RendererData.vbo->SetData(s_RendererData.vertices, vsize * sizeof(RendererData::Vertex));
		s_RendererData.ibo->SetData(s_RendererData.indices, isize * sizeof(uint32_t));

		Renderer::DrawIndexed(isize, s_RendererData.vao, s_RendererData.shader);
	}


	// Drawing functions
	void Renderer2D::DrawTriangle(const glm::vec3& p1, const glm::vec3& p2, const glm::vec3& p3, const glm::vec4& color)
	{
		static uint32_t calls = 0;
		calls += 1;

		/*
			Issue
			After 343 calls,
			the pointers become dangling for some reason
			need to check

			To Reproduce, remove the '= s_RendererData.vertices' in Renderer2D::Begin()
		*/

		*(s_RendererData.VertexPtrCurr++) = { p1.x, p1.y, p1.z, color.r, color.g, color.b, color.a };
		*(s_RendererData.VertexPtrCurr++) = { p2.x, p2.y, p2.z, color.r, color.g, color.b, color.a };
		*(s_RendererData.VertexPtrCurr++) = { p3.x, p3.y, p3.z, color.r, color.g, color.b, color.a };

		*(s_RendererData.IndexPtrCurr++) = s_RendererData.IndexValue++;
		*(s_RendererData.IndexPtrCurr++) = s_RendererData.IndexValue++;
		*(s_RendererData.IndexPtrCurr++) = s_RendererData.IndexValue++;
	}

	void Renderer2D::DrawQuad(const glm::vec3& pos, const glm::vec2& size, const glm::vec4& color)
	{
		*(s_RendererData.VertexPtrCurr++) = { pos.x, pos.y, pos.z, color.r, color.g, color.b, color.a };
		*(s_RendererData.VertexPtrCurr++) = { pos.x + size.x, pos.y, pos.z, color.r, color.g, color.b, color.a };
		*(s_RendererData.VertexPtrCurr++) = { pos.x + size.x, pos.y + size.y, pos.z, color.r, color.g, color.b, color.a };
		*(s_RendererData.VertexPtrCurr++) = { pos.x, pos.y + size.y, pos.z, color.r, color.g, color.b, color.a };

		*(s_RendererData.IndexPtrCurr++) = s_RendererData.IndexValue;
		*(s_RendererData.IndexPtrCurr++) = s_RendererData.IndexValue+1;
		*(s_RendererData.IndexPtrCurr++) = s_RendererData.IndexValue+2;
		*(s_RendererData.IndexPtrCurr++) = s_RendererData.IndexValue+2;
		*(s_RendererData.IndexPtrCurr++) = s_RendererData.IndexValue+3;
		*(s_RendererData.IndexPtrCurr++) = s_RendererData.IndexValue;

		s_RendererData.IndexValue += 4;
	}
	

}