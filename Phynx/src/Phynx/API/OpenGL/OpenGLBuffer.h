#pragma once
#include "Phynx/Renderer/Buffer.h"

namespace PX {

	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(uint32_t size, void* ptr, BufferDesc desc);
		~OpenGLVertexBuffer();
		void Bind() override;
		void Unbind() override;
		void ApplyLayout(LayoutData& layout) override;
		void SetData(void* dataptr, uint32_t size) override;

	private:
		uint32_t m_ID = 0;
	};

	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(uint32_t size, void* ptr, BufferDesc desc);
		~OpenGLIndexBuffer();
		void Bind() override;
		void Unbind() override;
		void SetData(void* dataptr, uint32_t size) override;

	private:
		uint32_t m_ID = 0;
	};

}
