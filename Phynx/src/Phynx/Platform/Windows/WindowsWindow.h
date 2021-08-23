#pragma once
#include "Core/Window.h"

namespace PX {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(WindowCreateStruct& data);
		virtual bool IsRunning() override;
		virtual void Update() override;
	};

}
