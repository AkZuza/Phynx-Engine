#pragma once
#include "Core/Context.h"

namespace PX {

	class OpenGLContext : public Context
	{
	public:
		OpenGLContext(void* handle);
		~OpenGLContext();
	};

}
