#pragma once
#include "Phynx/Core/Core.h"

namespace PX {

	class VertexArray
	{
	public:
		VertexArray() { ; }
		virtual ~VertexArray() { ; }

		static Shared<VertexArray> Create();

		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		//virtual void AddVertexBuffer() = 0;
		//virtual void SetIndexBuffer() = 0;
	};

}