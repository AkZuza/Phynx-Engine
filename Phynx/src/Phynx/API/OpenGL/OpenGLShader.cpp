#include "pxpch.h"
#include "OpenGLShader.h"
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

				/*LOG_CORE_INFO("================ {0} Error ===============", shader_type.c_str());
				LOG_CORE_INFO("{0}", errorLog.data());
				LOG_CORE_INFO("==========================================");*/
				// Log it later

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

}