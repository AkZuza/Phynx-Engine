#pragma once

#include <glm/glm.hpp>

namespace PX {

	class Renderer2D
	{
	public:
		// Prepare buffers and shaders
		static void Init();

		static void Begin();
		static void End();
		static void Flush();

		// Drawing functions
		static void DrawTriangle(const glm::vec3& p1, const glm::vec3& p2, const glm::vec3& p3, const glm::vec4& color);
		static void DrawQuad(const glm::vec3& pos, const glm::vec2& size, const glm::vec4& color);
	};

}