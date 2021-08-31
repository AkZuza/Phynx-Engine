#pragma once
#include "Phynx/Core/Core.h"

namespace PX {

	enum class BufferAccess
	{
		DRAW,
		READ,
		COPY
	};

	enum class BufferUsage
	{
		STREAM,
		DYNAMIC,
		STATIC
	};

	enum class DataType
	{
		FLOAT,
		DOUBLE,
		UINT,
		INT,
		INT64,
		UINT64
	};

	struct BufferDesc {
		BufferAccess access;
		BufferUsage usage;
	};


	struct VertexElement {
		uint32_t size;
		DataType type;
		bool normalize;
		std::string name;
	};

	class LayoutData
	{
	public:
		void PushElement(VertexElement element)
		{
			stride += element.size;
			m_elements.push_back(element);
		}

		uint64_t GetStride() const { return stride; }
		const std::vector<VertexElement>& GetElements() const { return m_elements; }

	private:
		uint64_t stride = 0;
		std::vector<VertexElement> m_elements;
	};

	class VertexBuffer
	{
	public:
		VertexBuffer() { ; }
		virtual ~VertexBuffer() { ; }
		static Shared<VertexBuffer> Create(uint32_t size, void* data = nullptr, BufferDesc desc = { BufferAccess::DRAW, BufferUsage::STATIC });

		virtual void Bind() = 0;
		virtual void Unbind() = 0;
		virtual void ApplyLayout(LayoutData& layout) = 0;

		virtual void SetData(void* dataptr, uint32_t size) = 0;
	};


	class IndexBuffer
	{
	public:
		IndexBuffer() { ; }
		virtual ~IndexBuffer() { ; }
		static Shared<IndexBuffer> Create(uint32_t size, void* data = nullptr, BufferDesc desc = { BufferAccess::DRAW, BufferUsage::STATIC });

		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual void SetData(void* dataptr, uint32_t size) = 0;
	};

}
