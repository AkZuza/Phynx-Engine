#include "pxpch.h"
#include "Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace PX {

	void Log::Init()
	{
		m_Core = spdlog::stdout_color_mt("Core");
		m_Client = spdlog::stdout_color_mt("Client");

		m_Core->set_pattern("%n [ %X ] : %v");
		m_Client->set_pattern("%n [ %X ] : %v");
	}

	std::shared_ptr<spdlog::logger> Log::GetCore()
	{
		return m_Core;
	}

	std::shared_ptr<spdlog::logger> Log::GetClient()
	{
		return m_Client;
	}

}