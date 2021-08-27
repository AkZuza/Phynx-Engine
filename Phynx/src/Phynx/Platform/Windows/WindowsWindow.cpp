#include "pxpch.h"
#include "WindowsWindow.h"
#include "Logging/Log.h"

#define GLFW_INCLUDE_NONE 1
#include <GLFW/glfw3.h>

namespace PX {

	WindowsWindow::WindowsWindow(WindowCreateStruct& data)
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		if (glfwInit() == GLFW_FALSE)
		{
			PX_CORE_ERROR("Failed to initialize GLFW");
			return;
		}

		// control frame rate
		glfwSwapInterval(1);

		m_pWindow = glfwCreateWindow(
			data.Width, data.Height,
			data.WindowName.c_str(),
			nullptr, nullptr
		);

		//assert m_pWindow

		// Create and bind context
		m_Context = Context::Create(m_pWindow);
		
		// set a pointer to the window data struct
		m_WindowData.WindowName = data.WindowName;
		m_WindowData.Height = data.Height;
		m_WindowData.Width = data.Width;
		m_WindowData.Flags = data.Flags;

		glfwSetWindowUserPointer((GLFWwindow*)m_pWindow, &m_WindowData);
	}

	bool WindowsWindow::IsRunning()
	{
		return !glfwWindowShouldClose((GLFWwindow*)m_pWindow);
	}

	void WindowsWindow::Update()
	{
		glfwPollEvents();
	 	glfwSwapBuffers((GLFWwindow*)m_pWindow);
	}

}