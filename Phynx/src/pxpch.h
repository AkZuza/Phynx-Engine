#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include <fstream>
#include <sstream>


// Platform dependant
#if defined(_WIN64) || defined(PX_PLATFORM_WINDOWS)
#	define WIN32_LEAN_AND_MEAN 1
#	include <Windows.h>
#endif
