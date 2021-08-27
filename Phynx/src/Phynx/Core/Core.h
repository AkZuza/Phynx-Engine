#pragma once
#include <memory>

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