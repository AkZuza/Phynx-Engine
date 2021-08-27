#pragma once
#include "Phynx/Core/Core.h"

namespace PX {

	class Shader
	{
	public:
		// soon to be depracated
		static Shared<Shader> Create(const std::string& vertex_src, const std::string& frag_src);
		static Shared<Shader> Create(std::ifstream& in_vs, std::ifstream& in_fs);

		virtual void Bind() = 0;
		virtual void Unbind() = 0;
	};

}
