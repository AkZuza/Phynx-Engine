#include "pxpch.h"
#include "VertexArray.h"
#include "API/OpenGL/OpenGLVertexArray.h"

namespace PX {

	Shared<VertexArray> VertexArray::Create()
	{
		return Shared<VertexArray>(new OpenGLVertexArray());
	}

}