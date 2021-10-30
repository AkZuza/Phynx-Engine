#pragma once

namespace PX {

	class Instrument
	{
	public:
		Instrument(const std::string& name);
		~Instrument();

	private:
		const std::string& m_Name;

	};

}
