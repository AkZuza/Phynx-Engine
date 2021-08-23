project "Phynx"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"

    targetdir(output_bin)
    objdir(output_int)

    pchheader "pxpch.h"
    pchsource "src/pxpch.cpp"

    files {
        "src/**.cpp",
        "src/**.h"
    }

    includedirs {
        "src/",
        "src/Phynx",
        "libs/glfw/include",
        "libs/Glad/include"
    }

    links {
        "glfw3",
        "Glad",
        "opengl32",
    }