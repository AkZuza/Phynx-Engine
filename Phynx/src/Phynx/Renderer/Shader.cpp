#include "pxpch.h"
#include "Shader.h"
#include "Phynx/API/OpenGL/OpenGLShader.h"
#include "Logging/Log.h"

namespace PX {

	Shared<Shader> Shader::Create(const std::string& vs, const std::string& fs)
	{
		return Shared<Shader>(new OpenGLShader(vs, fs));

		return nullptr;
	}

	Shared<Shader> Shader::Create(std::ifstream& in_vs, std::ifstream& in_fs)
	{
		std::string vs;
		std::string fs;
		std::string line;
		std::stringstream vstream;
		std::stringstream fstream;

		// logging and error checking
		// if any of the shaders are null pls break
		if (!in_vs.is_open() || !in_fs.is_open())
		{
			PX_CORE_ERROR("One or both of the shaders are not present at the location");
			return nullptr;
		}

		while (std::getline(in_vs, line))
			vstream << line << "\n";
		vs = vstream.str();

		while (std::getline(in_fs, line))
			fstream << line << "\n";
		fs = fstream.str();

		return Create(vs, fs);
	}

}