#pragma once
#include "Phynx/Core/Core.h"
#include "Context.h"

namespace PX
{
	enum WindowCreateFlags
	{
		WindowCreateFlag_None,
		WindowCreateFlag_NoResize = 1 << 1,
	};

	struct WindowCreateStruct
	{
		std::string WindowName;
		uint32_t Width;
		uint32_t Height;
		WindowCreateFlags Flags = WindowCreateFlag_None;
	};

	class Window
	{
	public:
		Window() { ; }
		virtual ~Window() { ; }
		static Shared<Window> Create(WindowCreateStruct& data);

		virtual uint32_t GetWidth() const { return m_WindowData.Width; }
		virtual uint32_t GetHeight() const { return m_WindowData.Height; }
		virtual void* GetWindowHandle() { return m_pWindow; }
		virtual const std::string& GetWindowName() const { return m_WindowData.WindowName; }
		const WindowCreateFlags GetCreateFlags() const { return m_WindowData.Flags; }

		virtual void Update() = 0;
		virtual bool IsRunning() = 0;

	protected:
		Shared<Context> m_Context;

		struct WindowData
		{
			std::string WindowName;
			uint32_t Width, Height;
			WindowCreateFlags Flags;
		} m_WindowData;

		void* m_pWindow = nullptr;

	};
}
