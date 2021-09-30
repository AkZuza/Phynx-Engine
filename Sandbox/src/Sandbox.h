#include <iostream>
#include <vector>
#include <Phynx.h>
#include <Phynx/API/OpenGL/OpenGLShader.h>

class Sandbox : public PX::Application
{
public:
	void Start() override;
	void Update() override;
	void OnEvent(PX::Event& event) override;


	// callbacks
	void OnWindowMoveEvent(PX::WindowMoveEvent& event);
	void OnMouseMoveEvent(PX::MouseMoveEvent& event);

	std::vector<glm::vec2> m_pos;

private:
	PX::Shared<PX::VertexArray> vao;
	PX::Shared<PX::VertexBuffer> vbo;
	PX::Shared<PX::IndexBuffer> ibo;
	PX::Shared<PX::OpenGLShader> shader;
};
