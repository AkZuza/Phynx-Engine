#include "pxpch.h"
#include "Window.h"
#include "Platform/Windows/WindowsWindow.h"

namespace PX {

	Shared<Window> Window::Create(WindowCreateStruct& data)
	{
		return Shared<Window>(new WindowsWindow(data));
	}

}