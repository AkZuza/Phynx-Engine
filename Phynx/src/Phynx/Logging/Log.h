#pragma once
#include <spdlog/spdlog.h>

namespace PX {

	class Log
	{
	public:
		static void Init();
		static std::shared_ptr<spdlog::logger> GetCore();
		static std::shared_ptr<spdlog::logger> GetClient();

	private:
		inline static std::shared_ptr<spdlog::logger> m_Client = nullptr;
		inline static std::shared_ptr<spdlog::logger> m_Core = nullptr;
	};

}

#if defined(PX_DEBUG)
#	define PX_LOG_INIT PX::Log::Init()
#	define PX_CORE_INFO(...)	PX::Log::GetCore()->info(__VA_ARGS__)
#	define PX_CORE_WARN(...)	PX::Log::GetCore()->warn(__VA_ARGS__)
#	define PX_CORE_ERROR(...)	PX::Log::GetCore()->error(__VA_ARGS__)

#	define PX_INFO(...)			PX::Log::GetClient()->info(__VA_ARGS__)
#	define PX_WARN(...)			PX::Log::GetClient()->warn(__VA_ARGS__)
#	define PX_ERROR(...)		PX::Log::GetClient()->error(__VA_ARGS__)
#else
#	define PX_LOG_INIT
#	define PX_CORE_INFO(...)	
#	define PX_CORE_WARN(...)	
#	define PX_CORE_ERROR(...)	

#	define PX_INFO(...)			
#	define PX_WARN(...)			
#	define PX_ERROR(...)		
#endif

