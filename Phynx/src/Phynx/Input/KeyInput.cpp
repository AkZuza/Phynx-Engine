#include "pxpch.h"
#include "KeyInput.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "../Core/Application.h"

namespace PX {

	bool KeyInput::IsPressed(uint32_t KeyCode)
	{
		uint32_t glfwKeyCode = 0;

		switch (KeyCode)
		{
		case PX_KEY_A: glfwKeyCode = GLFW_KEY_A; break;
		case PX_KEY_B: glfwKeyCode = GLFW_KEY_B; break;
		case PX_KEY_C: glfwKeyCode = GLFW_KEY_C; break;
		case PX_KEY_D: glfwKeyCode = GLFW_KEY_D; break;
		case PX_KEY_E: glfwKeyCode = GLFW_KEY_E; break;
		case PX_KEY_F: glfwKeyCode = GLFW_KEY_F; break;
		case PX_KEY_G: glfwKeyCode = GLFW_KEY_G; break;
		case PX_KEY_H: glfwKeyCode = GLFW_KEY_H; break;
		case PX_KEY_I: glfwKeyCode = GLFW_KEY_I; break;
		case PX_KEY_J: glfwKeyCode = GLFW_KEY_J; break;
		case PX_KEY_K: glfwKeyCode = GLFW_KEY_K; break;
		case PX_KEY_L: glfwKeyCode = GLFW_KEY_L; break;
		case PX_KEY_M: glfwKeyCode = GLFW_KEY_M; break;
		case PX_KEY_N: glfwKeyCode = GLFW_KEY_N; break;
		case PX_KEY_O: glfwKeyCode = GLFW_KEY_O; break;
		case PX_KEY_P: glfwKeyCode = GLFW_KEY_P; break;
		case PX_KEY_Q: glfwKeyCode = GLFW_KEY_Q; break;
		case PX_KEY_R: glfwKeyCode = GLFW_KEY_R; break;
		case PX_KEY_S: glfwKeyCode = GLFW_KEY_S; break;
		case PX_KEY_T: glfwKeyCode = GLFW_KEY_T; break;
		case PX_KEY_U: glfwKeyCode = GLFW_KEY_U; break;
		case PX_KEY_V: glfwKeyCode = GLFW_KEY_V; break;
		case PX_KEY_W: glfwKeyCode = GLFW_KEY_W; break;
		case PX_KEY_X: glfwKeyCode = GLFW_KEY_X; break;
		case PX_KEY_Y: glfwKeyCode = GLFW_KEY_Y; break;
		case PX_KEY_Z: glfwKeyCode = GLFW_KEY_Z; break;

		}
		return GLFW_PRESS == glfwGetKey((GLFWwindow*)Application::GetApplicationWindow()->GetWindowHandle(), glfwKeyCode);
	}

	bool KeyInput::IsReleased(uint32_t KeyCode)
	{
		uint32_t glfwKeyCode = 0;
		switch (KeyCode)
		{
		case PX_KEY_A: glfwKeyCode = GLFW_KEY_A; break;
		case PX_KEY_B: glfwKeyCode = GLFW_KEY_B; break;
		case PX_KEY_C: glfwKeyCode = GLFW_KEY_C; break;
		case PX_KEY_D: glfwKeyCode = GLFW_KEY_D; break;
		case PX_KEY_E: glfwKeyCode = GLFW_KEY_E; break;
		case PX_KEY_F: glfwKeyCode = GLFW_KEY_F; break;
		case PX_KEY_G: glfwKeyCode = GLFW_KEY_G; break;
		case PX_KEY_H: glfwKeyCode = GLFW_KEY_H; break;
		case PX_KEY_I: glfwKeyCode = GLFW_KEY_I; break;
		case PX_KEY_J: glfwKeyCode = GLFW_KEY_J; break;
		case PX_KEY_K: glfwKeyCode = GLFW_KEY_K; break;
		case PX_KEY_L: glfwKeyCode = GLFW_KEY_L; break;
		case PX_KEY_M: glfwKeyCode = GLFW_KEY_M; break;
		case PX_KEY_N: glfwKeyCode = GLFW_KEY_N; break;
		case PX_KEY_O: glfwKeyCode = GLFW_KEY_O; break;
		case PX_KEY_P: glfwKeyCode = GLFW_KEY_P; break;
		case PX_KEY_Q: glfwKeyCode = GLFW_KEY_Q; break;
		case PX_KEY_R: glfwKeyCode = GLFW_KEY_R; break;
		case PX_KEY_S: glfwKeyCode = GLFW_KEY_S; break;
		case PX_KEY_T: glfwKeyCode = GLFW_KEY_T; break;
		case PX_KEY_U: glfwKeyCode = GLFW_KEY_U; break;
		case PX_KEY_V: glfwKeyCode = GLFW_KEY_V; break;
		case PX_KEY_W: glfwKeyCode = GLFW_KEY_W; break;
		case PX_KEY_X: glfwKeyCode = GLFW_KEY_X; break;
		case PX_KEY_Y: glfwKeyCode = GLFW_KEY_Y; break;
		case PX_KEY_Z: glfwKeyCode = GLFW_KEY_Z; break;

		}
		return GLFW_RELEASE == glfwGetKey((GLFWwindow*)Application::GetApplicationWindow()->GetWindowHandle(), glfwKeyCode);
	}

}