#pragma once


#define EVENT_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
							virtual EventType GetType() { return EventType::type; }


namespace PX {
	
	enum class EventType
	{
		None,

		WindowCloseEvent, WindowMoveEvent, WindowResizeEvent, WindowMinimizeEvent, WindowMaximizeEvent,

		MouseMoveEvent, MousePressEvent, MouseReleaseEvent,

		KeyPressEvent, KeyReleaseEvent
	};

	class Event 
	{
	public:
		Event() {}
		virtual ~Event() {}
		EVENT_TYPE(None)

	};


#pragma region Event Classes

	// WINDOW EVENTS
	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() { ; }

		EVENT_TYPE(WindowCloseEvent)
	};


	class WindowMoveEvent : public Event
	{
	public:
		WindowMoveEvent(uint32_t xpos, uint32_t ypos) :
			m_X(xpos), m_Y(ypos)
		{}

		EVENT_TYPE(WindowMoveEvent)

	private:
		uint32_t m_X;
		uint32_t m_Y;
	};

	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(uint32_t width, uint32_t height)
			: m_Width(width), m_Height(height)
		{}

		uint32_t GetWidth() { return m_Width; }
		uint32_t GetHeight() { return m_Height; }

		EVENT_TYPE(WindowResizeEvent)
		
	private:
		uint32_t m_Width;
		uint32_t m_Height;
	};


	// MOUSE EVENTS
	class MouseMoveEvent : public Event
	{
	public:
		MouseMoveEvent(double x, double y)
			: m_X(x), m_Y(y) {}

		double GetXPos() { return m_X; }
		double GetYPos() { return m_Y; }

		EVENT_TYPE(MouseMoveEvent)

	private:
		double m_X, m_Y;

	};

	class MousePressEvent : public Event
	{
	public:
		MousePressEvent(uint32_t keyCode)
			: m_KeyCode(keyCode)
		{}

		uint32_t GetKeyCode()
		{
			return m_KeyCode;
		}

		EVENT_TYPE(MousePressEvent)

	private:
		uint32_t m_KeyCode;
	};

	class MouseReleaseEvent : public Event
	{
	public:
		MouseReleaseEvent(uint32_t keyCode)
			: m_KeyCode(keyCode)
		{}

		uint32_t GetKeyCode()
		{
			return m_KeyCode;
		}

		EVENT_TYPE(MousePressEvent)

	private:
		uint32_t m_KeyCode;
	};


	// KEY EVENTS
	class KeyReleaseEvent : public Event
	{
	public:
		KeyReleaseEvent(uint32_t keyCode)
			: m_KeyCode(keyCode)
		{}

		uint32_t GetKeyCode()
		{
			return m_KeyCode;
		}

		EVENT_TYPE(MousePressEvent)

	private:
		uint32_t m_KeyCode;
	};

	class KeyPressEvent : public Event
	{
	public:
		KeyPressEvent(uint32_t keyCode)
			: m_KeyCode(keyCode)
		{}

		uint32_t GetKeyCode()
		{
			return m_KeyCode;
		}

		EVENT_TYPE(MousePressEvent)

	private:
		uint32_t m_KeyCode;
	};

#pragma endregion



	class EventDispatcher
	{
	public:
		EventDispatcher(Event& event)
			: m_Event(event) {}

		static void SendEvent(Event& event);

		template<typename T, typename F>
		void Dispatch(const F& func)
		{
			if (T::GetStaticType() == m_Event.GetType())
				func(dynamic_cast<T&>(m_Event));
		}

	private:
		Event& m_Event;
	};

}
