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

		// These are not accessible through the Shader class
		// only through OpenGLShader
		void UploadUniform1f(const std::string& uniform, float v1);
		void UploadUniform2f(const std::string& uniform, float v1, float v2);
		void UploadUniform3f(const std::string& uniform, float v1, float v2, float v3);
		void UploadUniform4f(const std::string& uniform, float v1, float v2, float v3, float v4);

		uint32_t GetUniform(const std::string& uniform);
	
	private:
		uint32_t m_ID;

		// uniforms
		std::unordered_map<std::string, uint32_t> m_Uniforms;
	};

}
