#pragma once

#include "Renderer/Renderer.h"

namespace PX {

	class OpenGLRenderer : public Renderer
	{
	public:
		void Impl_Clear(float r, float g, float b, float a);
		void Impl_Draw(uint32_t count);
		void Impl_DrawIndexed(uint32_t count);
	};

}
