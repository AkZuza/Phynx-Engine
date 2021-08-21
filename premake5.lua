workspace "Phynx-Engine"
    configurations {"Release", "Debug", "Test"}
    architecture "x86_64"

    startproject "Sandbox"

    project_dir = "%{cfg.shortname}/%{cfg.architecture}/%{prj.name}"
    output_bin = ("%{wks.location}/build/bin/" .. project_dir)
    output_int = ("%{wks.location}/build/bin/" .. project_dir) 

include "Phynx"
include "Sandbox"