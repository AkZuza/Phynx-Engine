#include "pxpch.h"
#include "Renderer2D.h"

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

	} s_RendererData;

	void Renderer2D::Init()
	{
		s_RendererData.vao = VertexArray::Create();
		
		// Vertex Buffer
		s_RendererData.vbo = VertexBuffer::Create(
			sizeof(s_RendererData.vertices),
			nullptr,
			{ BufferAccess::DRAW, BufferUsage::DYNAMIC }
		);

		// Apply layout
		LayoutData layout;
		layout.PushElement({ 3, DataType::FLOAT, false, "pos" });
		layout.PushElement({ 4, DataType::FLOAT, false, "col" });

		s_RendererData.vbo->ApplyLayout(layout);

		s_RendererData.ibo = IndexBuffer::Create(
			sizeof(s_RendererData.indices),
			nullptr,
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
	}

}