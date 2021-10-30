#pragma once
#include "Phynx/Input/KeyCodes.h"

namespace PX {

	enum class Key
	{
		// Alphabets
		A = 1, B, C, D, E, F, G, H, I, J, K, L, M, N, O,
		P, Q, R, S, T, U, V, W, X, Y, Z,

		// Digits
		Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9, Num0
	};

	class KeyInput
	{
	public:
		static bool IsPressed(uint32_t KeyCode);
		static bool IsReleased(uint32_t KeyCode);

		static char KeyCodeToChar(uint32_t KeyCode) { return (char)(KeyCode + 64); }
	};

}