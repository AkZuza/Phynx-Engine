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

	bool MouseInput::IsPressed(MouseButton keyCode)
	{
		uint32_t glfwCode = 0;

		switch (keyCode)
		{
		case MouseButton::Left: glfwCode = GLFW_MOUSE_BUTTON_LEFT; break;
		case MouseButton::Right: glfwCode = GLFW_MOUSE_BUTTON_RIGHT; break;
		case MouseButton::Middle: glfwCode = GLFW_MOUSE_BUTTON_MIDDLE; break;

		default:
			return false;
		}

		return glfwGetMouseButton((GLFWwindow*)Application::GetApplicationWindow()->GetWindowHandle(), glfwCode) == GLFW_PRESS;
	}

	bool MouseInput::IsReleased(MouseButton keyCode)
	{
		uint32_t glfwCode = 0;

		switch (keyCode)
		{
		case MouseButton::Left: glfwCode = GLFW_MOUSE_BUTTON_LEFT; break;
		case MouseButton::Right: glfwCode = GLFW_MOUSE_BUTTON_RIGHT; break;
		case MouseButton::Middle: glfwCode = GLFW_MOUSE_BUTTON_MIDDLE; break;

		default:
			return false;
		}

		return glfwGetMouseButton((GLFWwindow*)Application::GetApplicationWindow()->GetWindowHandle(), glfwCode) == GLFW_RELEASE;
	}
}