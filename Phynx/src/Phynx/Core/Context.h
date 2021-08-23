#pragma once
#include "Phynx/Core/Core.h"

namespace PX {

	class Context
	{
	public:
		static Shared<Context> Create(void* handle);
		Context() { ; }
		virtual ~Context() { ; }
	};

}