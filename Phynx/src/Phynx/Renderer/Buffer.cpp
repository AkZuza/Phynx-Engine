#include "pxpch.h"
#include "Buffer.h"
#include "Phynx/API/OpenGL/OpenGLBuffer.h"

namespace PX {

	Shared<VertexBuffer> VertexBuffer::Create(uint32_t size, void* data, BufferDesc desc)
	{
		return Shared<VertexBuffer>(new OpenGLVertexBuffer(size, data, desc));
		return nullptr;
	}

	Shared<IndexBuffer> IndexBuffer::Create(uint32_t size, void* data, BufferDesc desc)
	{
		return Shared<IndexBuffer>(new OpenGLIndexBuffer(size, data, desc));
		return nullptr;
	}

}