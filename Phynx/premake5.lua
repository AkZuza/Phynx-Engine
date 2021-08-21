project "Phynx"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"

    targetdir(output_bin)
    objdir(output_int)

    files {
        "src/**.cpp",
        "src/**.h"
    }