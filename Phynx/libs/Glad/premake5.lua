project "Glad"
kind "StaticLib"
language "C++"
cppdialect "C++17"

targetdir("build/%{cfg.system}/%{cfg.architecture}/%{cfg.shortname}/bin")
objdir("build/%{cfg.system}/%{cfg.architecture}/%{cfg.shortname}/bin-int")

files {
	"src/**.c",
    "include/**.h"
}

includedirs {
	"include"
}