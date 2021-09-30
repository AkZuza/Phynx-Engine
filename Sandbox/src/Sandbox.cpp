#include "Sandbox.h"
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
}

void Sandbox::Update()
{
	PX::Renderer::Clear(0.3f, 0.9f, 0.7f, 1.f);

	PX::Renderer2D::Begin();

	PX::Renderer2D::DrawTriangle(
		{ -0.5f, -0.5f, 1.f },
		{ 0.5f, -0.5f, 1.f },
		{ 0.0f,  0.5f, 1.f },
		{ 0.3f, 0.7f, 0.8f, 1.f }
	);

	std::cout << "Mouse Pos X: " << PX::MouseInput::GetXPos() << "   Y: " << PX::MouseInput::GetYPos() << "\n"; 

	PX::Renderer2D::End();
	PX::Renderer2D::Flush();
}

void Sandbox::OnEvent(PX::Event& event)
{
	PX::EventDispatcher dispatcher(event);

	/*dispatcher.Dispatch<PX::WindowMoveEvent>([this](PX::Event& event)
		{
			this->OnWindowMoveEvent(dynamic_cast<PX::WindowMoveEvent&>(event));
		});*/

	dispatcher.Dispatch<PX::WindowMoveEvent>(BIND_EVENT_FN(OnWindowMoveEvent));
	dispatcher.Dispatch<PX::MouseMoveEvent>(BIND_EVENT_FN(OnMouseMoveEvent));

}

void Sandbox::OnWindowMoveEvent(PX::WindowMoveEvent& event)
{
	int x = 0;
}

void Sandbox::OnMouseMoveEvent(PX::MouseMoveEvent& event)
{
	std::cout << "Mouse Pos X: " << event.GetXPos() << "   Y: " << event.GetYPos() << std::endl;
}
