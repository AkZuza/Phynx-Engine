#include "pxpch.h"
#include "OpenGLContext.h"
#include "Logging/Log.h"

#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

namespace PX {

	OpenGLContext::OpenGLContext(void* handle)
	{
		glfwMakeContextCurrent((GLFWwindow*)handle);
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);


		// output context description
		std::string vendor = (char*)glGetString(GL_VENDOR);
		std::string renderer = (char*)glGetString(GL_RENDERER);
		std::string version = (char*)glGetString(GL_VERSION);
		std::string shading_version = (char*)glGetString(GL_SHADING_LANGUAGE_VERSION);

		PX_CORE_INFO("API: OpenGL");
		PX_CORE_INFO("Vendor: {0}", vendor);
		PX_CORE_INFO("Renderer: {0}", renderer);
		PX_CORE_INFO("Version: {0}", version);
		PX_CORE_INFO("Shading Language Version: {0}", shading_version);
	}

	OpenGLContext::~OpenGLContext()
	{
		glfwMakeContextCurrent(nullptr);
	}

}