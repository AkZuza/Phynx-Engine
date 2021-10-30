#include "pxpch.h"
#include "WindowsWindow.h"
#include "Logging/Log.h"
#include "Event/Event.h"
#include "Phynx/Input/KeyCodes.h"


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
				WindowData* windowdata = (WindowData*)glfwGetWindowUserPointer(window);
				windowdata->Height = height;
				windowdata->Width = width;

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

		glfwSetKeyCallback((GLFWwindow*)m_pWindow, [](GLFWwindow* window, int keyCode, int scanCode, int action, int modifier)
			{
				uint32_t PXKey = 0;

				switch (keyCode)
				{
				case GLFW_KEY_A: PXKey = PX_KEY_A; break;
				case GLFW_KEY_B: PXKey = PX_KEY_B; break;
				case GLFW_KEY_C: PXKey = PX_KEY_C; break;
				case GLFW_KEY_D: PXKey = PX_KEY_D; break;
				case GLFW_KEY_E: PXKey = PX_KEY_E; break;
				case GLFW_KEY_F: PXKey = PX_KEY_F; break;
				case GLFW_KEY_G: PXKey = PX_KEY_G; break;
				case GLFW_KEY_H: PXKey = PX_KEY_H; break;
				case GLFW_KEY_I: PXKey = PX_KEY_I; break;
				case GLFW_KEY_J: PXKey = PX_KEY_J; break;
				case GLFW_KEY_K: PXKey = PX_KEY_K; break;
				case GLFW_KEY_L: PXKey = PX_KEY_L; break;
				case GLFW_KEY_M: PXKey = PX_KEY_M; break;
				case GLFW_KEY_N: PXKey = PX_KEY_N; break;
				case GLFW_KEY_O: PXKey = PX_KEY_O; break;
				case GLFW_KEY_P: PXKey = PX_KEY_P; break;
				case GLFW_KEY_Q: PXKey = PX_KEY_Q; break;
				case GLFW_KEY_R: PXKey = PX_KEY_R; break;
				case GLFW_KEY_S: PXKey = PX_KEY_S; break;
				case GLFW_KEY_T: PXKey = PX_KEY_T; break;
				case GLFW_KEY_U: PXKey = PX_KEY_U; break;
				case GLFW_KEY_V: PXKey = PX_KEY_V; break;
				case GLFW_KEY_W: PXKey = PX_KEY_W; break;
				case GLFW_KEY_X: PXKey = PX_KEY_X; break;
				case GLFW_KEY_Y: PXKey = PX_KEY_Y; break;
				case GLFW_KEY_Z: PXKey = PX_KEY_Z; break;

				}

				if (action == GLFW_PRESS)
				{
					KeyPressEvent event(PXKey);
					EventDispatcher::SendEvent(event);
				}
				else if (action == GLFW_RELEASE)
				{
					KeyReleaseEvent event(PXKey);
					EventDispatcher::SendEvent(event);
				}
			});

		glfwSetMouseButtonCallback((GLFWwindow*)m_pWindow, [](GLFWwindow* window, int keyCode, int action, int mod)
			{
				
				uint32_t PxKey = 0;

				if (keyCode == GLFW_MOUSE_BUTTON_LEFT)
					PxKey = PX_MOUSE_LEFT;
				else if (keyCode == GLFW_MOUSE_BUTTON_RIGHT)
					PxKey = PX_MOUSE_RIGHT;
				else if (keyCode == GLFW_MOUSE_BUTTON_MIDDLE)
					PxKey = PX_MOUSE_MIDDLE;

				if (action == GLFW_PRESS)
				{
					KeyPressEvent event(PxKey);
					EventDispatcher::SendEvent(event);
				}
				else if (action == GLFW_RELEASE)
				{
					KeyReleaseEvent event(PxKey);
					EventDispatcher::SendEvent(event);
				}
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