#include "pxpch.h"
#include "OpenGLBuffer.h"

#include <glad/glad.h>

namespace PX {

	uint32_t DetermineDataTyoe(DataType type)
	{
		switch (type)
		{
		case DataType::FLOAT:
			return GL_FLOAT;

		case DataType::DOUBLE:
			return GL_DOUBLE;

		case DataType::INT:
			return GL_INT;

		case DataType::UINT:
			return GL_UNSIGNED_INT;
		}

		return 0;
	}

	uint32_t DetermineDataTypeSize(DataType type)
	{
		switch (type)
		{
		case DataType::FLOAT:
			return sizeof(float);

		case DataType::DOUBLE:
			return sizeof(double);

		case DataType::UINT:
			return sizeof(uint32_t);

		case DataType::INT:
			return sizeof(int32_t);
		}

		return 0;
	}

	uint32_t DetermineBufferDesc(BufferDesc& desc)
	{
		if (desc.usage == BufferUsage::STATIC && desc.access == BufferAccess::DRAW)
			return GL_STATIC_DRAW;

		if (desc.usage == BufferUsage::STATIC && desc.access == BufferAccess::COPY)
			return GL_STATIC_COPY;

		if (desc.usage == BufferUsage::STATIC && desc.access == BufferAccess::READ)
			return GL_STATIC_READ;

		if (desc.usage == BufferUsage::STREAM && desc.access == BufferAccess::DRAW)
			return GL_STREAM_DRAW;

		if (desc.usage == BufferUsage::STREAM && desc.access == BufferAccess::COPY)
			return GL_STREAM_COPY;

		if (desc.usage == BufferUsage::STREAM && desc.access == BufferAccess::READ)
			return GL_STREAM_READ;

		if (desc.usage == BufferUsage::DYNAMIC && desc.access == BufferAccess::DRAW)
			return GL_DYNAMIC_DRAW;

		if (desc.usage == BufferUsage::DYNAMIC && desc.access == BufferAccess::COPY)
			return GL_DYNAMIC_COPY;

		if (desc.usage == BufferUsage::DYNAMIC && desc.access == BufferAccess::READ)
			return GL_DYNAMIC_READ;

		return 0;
	}

	OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t size, void * ptr, BufferDesc desc)
	{
		glGenBuffers(1, &m_ID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, ptr, DetermineBufferDesc(desc));
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		glDeleteBuffers(1, &m_ID);
	}

	void OpenGLIndexBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
	}

	void OpenGLIndexBuffer::Unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	void OpenGLIndexBuffer::SetData(void* dataptr, uint32_t size)
	{
		glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, size, dataptr);
	}

	OpenGLVertexBuffer::OpenGLVertexBuffer(uint32_t size, void * ptr, BufferDesc desc)
	{
		glGenBuffers(1, &m_ID);
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
		glBufferData(GL_ARRAY_BUFFER, size, ptr, DetermineBufferDesc(desc));
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &m_ID);
	}

	void OpenGLVertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	}

	void OpenGLVertexBuffer::Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void OpenGLVertexBuffer::ApplyLayout(LayoutData & layout)
	{
		uint64_t stride = layout.GetStride();
		uint32_t offset = 0;
		auto& elements = layout.GetElements();
		for (uint32_t index = 0; index < elements.size(); ++index)
		{
			auto& element = elements[index];
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, element.size, DetermineDataTyoe(element.type), element.normalize, stride * DetermineDataTypeSize(element.type), reinterpret_cast<void*>(offset));
			offset += element.size * DetermineDataTypeSize(element.type);
		}
	}

	void OpenGLVertexBuffer::SetData(void* dataptr, uint32_t size)
	{
		glBufferSubData(GL_ARRAY_BUFFER, 0, size, dataptr);
	}

}