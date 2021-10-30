#pragma once
#include "Phynx/Event/Event.h"

namespace PX {

	class Layer
	{
	public:
		virtual void OnEvent(Event& event) {};
		virtual void OnCreate() {}
		virtual void OnDestroy() {}
		virtual void OnRender() {}
		virtual void OnUpdate() = 0;
	};

}
