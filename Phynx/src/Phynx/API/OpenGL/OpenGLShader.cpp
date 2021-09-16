#include "pxpch.h"
#include "OpenGLShader.h"
#include "Logging/Log.h"
#include <glad/glad.h>

namespace PX {

	OpenGLShader::OpenGLShader(const std::string& vs, const std::string& fs)
	{
		auto compile_shader = [](const std::string& src, uint32_t id, const std::string& shader_type)
		{
			const char* c_src = src.c_str();
			glShaderSource(id, 1, &c_src, nullptr);
			glCompileShader(id);

			GLint isCompiled = 0;
			glGetShaderiv(id, GL_COMPILE_STATUS, &isCompiled);
			if (isCompiled == GL_FALSE)
			{
				GLint maxLength = 0;
				glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

				std::vector<GLchar> errorLog(maxLength);
				glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

				PX_CORE_WARN("================ {0} Error ===============", shader_type.c_str());
				PX_CORE_WARN("{0}", errorLog.data());
				PX_CORE_WARN("==========================================");

				glDeleteShader(id);
				return;
			}
		};

		uint32_t vertex = glCreateShader(GL_VERTEX_SHADER);
		uint32_t frag = glCreateShader(GL_FRAGMENT_SHADER);

		compile_shader(vs, vertex, "Vertex Shader");
		compile_shader(fs, frag,   "Fragment Shader");

		m_ID = glCreateProgram();

		glAttachShader(m_ID, vertex);
		glAttachShader(m_ID, frag);

		glLinkProgram(m_ID);

		glDetachShader(m_ID, vertex);
		glDetachShader(m_ID, frag);

		glDeleteShader(vertex);
		glDeleteShader(frag);

	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(m_ID);
	}

	void OpenGLShader::Bind()
	{
		glUseProgram(m_ID);
	}

	void OpenGLShader::Unbind()
	{
		glUseProgram(0);
	}

#pragma region Uniform Function
	void OpenGLShader::UploadUniform1f(const std::string& uniform, float v1)
	{
		glUniform1f(GetUniform(uniform), v1);
	}

	void OpenGLShader::UploadUniform2f(const std::string& uniform, float v1, float v2)
	{
		glUniform2f(GetUniform(uniform), v1, v2);
	}

	void OpenGLShader::UploadUniform3f(const std::string& uniform, float v1, float v2, float v3)
	{
		glUniform3f(GetUniform(uniform), v1, v2, v3);
	}

	void OpenGLShader::UploadUniform4f(const std::string& uniform, float v1, float v2, float v3, float v4)
	{
		glUniform4f(GetUniform(uniform), v1, v2, v3, v4);
	}

	uint32_t OpenGLShader::GetUniform(const std::string& uniform)
	{
		if (m_Uniforms.find(uniform) == m_Uniforms.end())
		{
			uint32_t loc = glGetUniformLocation(m_ID, uniform.c_str());
			if (loc == -1)
				PX_CORE_WARN("{0} Uniform not found", uniform);

			m_Uniforms[uniform] = loc;
		}
		
		return m_Uniforms[uniform];
	}

#pragma endregion

}