#pragma once
#include <memory>

// Debug
#if defined(PX_DEBUG)
#	if	defined(PX_ENABLE_DEBUGBRK)
#		define PX_DEBUGBRK() _debugbreak()
#	endif
#	if defined(PX_ENABLE_ASSERT)
#		define PX_ASSERT(x) if(!(x)) {PX_DEBUGBRK(); }
#	endif
#else
#	define PX_DEBUGBRK() 
#	define PX_ASSERT(x)
#endif


namespace PX {

	// Graphics API enumeration
	enum class API
	{
		OpenGL, // in progress
		D3D12,  // not implemented
		D3D11,  // not implemented
		Vulkan, // not implemented
		None,
	};

	template<class T>
	using Shared = std::shared_ptr<T>;

	template<class T>
	using Unique = std::unique_ptr<T>;

}

#define BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }
#define BIT(x) (1 << x)

#include "Phynx/Logging/Log.h"