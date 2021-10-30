#include "Sandbox.h"
#include "ExampleLayer.h"
#include <Windows.h>


PX::Application* PX::CreateApplicationInstance()
{
	return new Sandbox();
}

uint32_t loc = 0;

void Sandbox::Start()
{
	//PX::EventDispatcher::SetEventProc(BIND_EVENT_FN(OnEvent));
	PX::WindowCreateStruct data;
	data.Width = 900;
	data.Height = 900;
	data.WindowName = "Sandbox";


	CreateApplicationWindow(data);

	PushLayer(new ExampleLayer());
}

void Sandbox::OnUpdate()
{
	PX::Renderer::Clear(0.3f, 0.9f, 0.7f, 1.f);

	PX::Renderer2D::Begin();

	PX::Renderer2D::DrawTriangle(
		{ -0.5f, -0.5f, 1.f },
		{ 0.5f, -0.5f, 1.f },
		{ 0.0f,  0.5f, 1.f },
		{ 0.3f, 0.7f, 0.8f, 1.f }
	);

	//std::cout << "Mouse Pos X: " << PX::MouseInput::GetXPos() << "   Y: " << PX::MouseInput::GetYPos() << "\n"; 

	for (uint32_t i = (uint32_t)PX::Key::A; i <= (uint32_t)PX::Key::Z; ++i)
	{
		if (PX::KeyInput::IsPressed(i))
		{
			std::cout << PX::KeyInput::KeyCodeToChar(i) << "\n";
		}
	}

	if (PX::MouseInput::IsPressed(PX::MouseButton::Left))
		std::cout << "Clicked" << "\n";


	PX::Renderer2D::End();
	PX::Renderer2D::Flush();
}

void Sandbox::OnEvent(PX::Event& event)
{
	PX::EventDispatcher dispatcher(event);
}
