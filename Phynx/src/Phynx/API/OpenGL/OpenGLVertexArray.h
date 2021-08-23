#pragma once
#include "Phynx/Renderer/VertexArray.h"

namespace PX {

	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();
		~OpenGLVertexArray();

		void Bind() override;
		void Unbind() override;

	private:
		uint32_t m_ID = 0;
	};

}
