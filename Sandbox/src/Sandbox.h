#include <iostream>
#include <vector>
#include <Phynx.h>

class Sandbox : public PX::Application
{
public:
	void Start() override;
	void Update() override;

private:
	PX::Shared<PX::VertexArray> vao;
	PX::Shared<PX::VertexBuffer> vbo;
	PX::Shared<PX::IndexBuffer> ibo;
	PX::Shared<PX::Shader> shader;
};
