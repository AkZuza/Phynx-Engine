#include "pxpch.h"
#include "MouseInput.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "../Core/Application.h"

namespace PX {

	double MouseInput::GetXPos()
	{
		double x = 0.f;
		glfwGetCursorPos((GLFWwindow*)Application::GetApplicationWindow()->GetWindowHandle(),&x, nullptr);
		return x;
	}

	double MouseInput::GetYPos()
	{
		double y = 0.f;
		glfwGetCursorPos((GLFWwindow*)Application::GetApplicationWindow()->GetWindowHandle(), nullptr, &y);
		return y;
	}

}