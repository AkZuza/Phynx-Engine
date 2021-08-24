project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir(output_bin)
    objdir(output_int)

    files {
        "src/**.cpp",
        "src/**.h"
    }

    includedirs {
        "../Phynx/src/",
        "../Phynx/libs/Glad/include"
    }

    links {
        "Phynx"
    }