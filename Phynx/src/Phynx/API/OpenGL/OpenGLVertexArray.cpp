#include "pxpch.h"
#include "OpenGLVertexArray.h"
#include <glad/glad.h>

namespace PX {

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glGenVertexArrays(1, &m_ID);
		glBindVertexArray(m_ID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_ID);
	}

	void OpenGLVertexArray::Bind()
	{
		glBindVertexArray(m_ID);
	}

	void OpenGLVertexArray::Unbind()
	{
		glBindVertexArray(0);
	}

}