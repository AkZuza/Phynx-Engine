#include "pxpch.h"
#include "Context.h"

#include "API/OpenGL/OpenGLContext.h"

namespace PX {

	Shared<Context> Context::Create(void* handle)
	{
		return Shared<Context>(new OpenGLContext(handle));
	}

}