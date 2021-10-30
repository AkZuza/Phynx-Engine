#pragma once

#include "Phynx.h"

class ExampleLayer : public PX::Layer
{
public:
	void OnUpdate()
	{
		PX::Renderer::Clear(0.2f, 0.9f, 0.1f, 1.f);
		PX::Renderer2D::Begin();
		PX::Renderer2D::DrawQuad({ -0.5f, -0.5f, 0.f }, { 1.f, 1.f }, { 0.4f, 0.0f, 0.9f, 1.f });
		PX::Renderer2D::End();
		PX::Renderer2D::Flush();
	}
};
