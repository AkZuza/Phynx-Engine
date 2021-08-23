#pragma once
#include "Phynx/Renderer/Shader.h"

namespace PX {

	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(const std::string& vs, const std::string& fs);
		~OpenGLShader();

		void Bind() override;
		void Unbind() override;
	
	private:
		uint32_t m_ID;
	};

}
