#include "pxpch.h"
#include "Event.h"
#include "Phynx/Core/Application.h"

namespace PX {

	void EventDispatcher::SendEvent(Event& event)
	{
		Application::GetApplicationInstance()->OnEvent(event);
	}

}