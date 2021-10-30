#pragma once
#include "Phynx/Input/KeyCodes.h"

namespace PX {

	enum class MouseButton
	{
		Left = 27, Right, Middle
	};

	class MouseInput
	{
	public:
		static double GetXPos();
		static double GetYPos();

		static bool IsPressed(MouseButton keyCode);
		static bool IsReleased(MouseButton keyCode);
	};


}
