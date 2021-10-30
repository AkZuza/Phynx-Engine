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
        "libs/Glad/include",
        "libs/spdlog/include",
        "libs/glm"
    }

    links {
        "glfw3",
        "Glad",
        "opengl32",
    }

    filter "configurations:Release"
        defines { "PX_RELEASE"}

    filter "configurations:Debug"
        defines { "PX_DEBUG"}

    filter "configurations:Debug"
        defines { "PX_TEST"}