#include "pxpch.h"
#include "OpenGLContext.h"

#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace PX {

	OpenGLContext::OpenGLContext(void* handle)
	{
		glfwMakeContextCurrent((GLFWwindow*)handle);
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	}

	OpenGLContext::~OpenGLContext()
	{
		glfwMakeContextCurrent(nullptr);
	}

}