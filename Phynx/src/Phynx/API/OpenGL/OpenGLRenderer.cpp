#include "pxpch.h"
#include "OpenGLRenderer.h"

#include <glad/glad.h>

namespace PX {

	void OpenGLRenderer::Impl_Clear(float r, float g, float b, float a)
	{
		glClearColor(r, g, b, a);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void OpenGLRenderer::Impl_Draw(uint32_t count)
	{
		glDrawArrays(GL_TRIANGLES, 0, count);
	}

	void OpenGLRenderer::Impl_DrawIndexed(uint32_t count)
	{
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
	}

}
