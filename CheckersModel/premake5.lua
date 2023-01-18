project "CheckersModel"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"

    targetdir("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "src/**.cpp",
        "src/**.h"
    }

     filter { "configurations:Debug" }
        filter "system:windows"
		    buildoptions "/MTd"
		runtime "Debug"
		symbols "on"

	filter { "configurations:Release"}
        filter "system:windows"
		    buildoptions "/MT"
		runtime "Release"
		optimize "on"