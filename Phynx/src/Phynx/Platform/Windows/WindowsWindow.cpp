#include "pxpch.h"
#include "WindowsWindow.h"
#include "Logging/Log.h"
#include "Event/Event.h"

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

		m_pWindow = glfwCreateWindow(
			data.Width, data.Height,
			data.WindowName.c_str(),
			nullptr, nullptr
		);

		//assert m_pWindow

		// Create and bind context
		m_Context = Context::Create(m_pWindow);

		// control frame rate
		glfwSwapInterval(1);

		
		// set a pointer to the window data struct
		m_WindowData.WindowName = data.WindowName;
		m_WindowData.Height = data.Height;
		m_WindowData.Width = data.Width;
		m_WindowData.Flags = data.Flags;

		glfwSetWindowUserPointer((GLFWwindow*)m_pWindow, &m_WindowData);


		// Set event callbacks
		glfwSetWindowPosCallback((GLFWwindow*)m_pWindow, [](GLFWwindow* win, int x, int y)
			{
				//PX_CORE_INFO("Position changed X:{0}  Y:{1}", x, y);
				WindowMoveEvent event(x, y);
				EventDispatcher::SendEvent(event);
			});

		glfwSetErrorCallback([](int code, const char* msg)
			{
				PX_CORE_ERROR("Error Code {0} : {1}", code, msg);
			});

		glfwSetWindowSizeCallback((GLFWwindow*)m_pWindow, [](GLFWwindow* window, int width, int height)
			{
				//PX_CORE_INFO("Window Size X:{0}  Y:{1}", width, height);
				WindowResizeEvent event(width, height);
				EventDispatcher::SendEvent(event);

			});

		glfwSetWindowCloseCallback((GLFWwindow*)m_pWindow, [](GLFWwindow* window)
			{
				//PX_CORE_INFO("Window Closed");
				WindowCloseEvent event;
				EventDispatcher::SendEvent(event);
			});

		glfwSetCursorPosCallback((GLFWwindow*)m_pWindow, [](GLFWwindow* window, double x, double y)
			{
				MouseMoveEvent event(x, y);
				EventDispatcher::SendEvent(event);
			});
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
	
	WindowsWindow::~WindowsWindow()
	{
		m_Context->~Context();
		m_Context = nullptr;
		glfwDestroyWindow((GLFWwindow*)m_pWindow);
		glfwTerminate();
	}

}