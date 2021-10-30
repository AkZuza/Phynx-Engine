workspace "Phynx-Engine"
    configurations {"Release", "Debug", "Test"}
    architecture "x86_64"

    startproject "Sandbox"

    project_dir = "%{cfg.shortname}/%{cfg.architecture}/%{prj.name}"
    output_bin = ("%{wks.location}/build/bin/" .. project_dir)
    output_int = ("%{wks.location}/build/bin/" .. project_dir) 

    group "Dependencies"
        include "Phynx/libs/glfw"
        include "Phynx/libs/Glad"

    group ""
    
include "Phynx"
include "Sandbox"