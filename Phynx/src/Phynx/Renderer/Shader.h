#pragma once
#include "Phynx/Core/Core.h"

namespace PX {

	class Shader
	{
	public:
		static Shared<Shader> Create(const std::string& vertex_src, const std::string& frag_src);
		// soon to be depracated
		static Shared<Shader> CreateFromFile(const std::string& vertex_shader_path, const std::string& fragment_shader_path);

		virtual void Bind() = 0;
		virtual void Unbind() = 0;
	};

}
