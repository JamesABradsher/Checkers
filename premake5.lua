workspace "Checkers"

    configurations {
        "Debug",
        "Release"
    }

    filter "system:windows"
		architecture"x64"

    startproject "CheckersRenderer"

outputdir = "%{cfg.buildcfg}.%{cfg.system}.%{cfg.architecture}"

include "CheckersModel"
include "CheckersRenderer"

newaction {
	trigger     = "clean",
	description = "Removes binaries and project files",
	execute     = function ()
		print("Removing binaries")
		os.rmdir("./bin/")
		print("Removing intermediates")
		os.rmdir("./bin-int/")
		print("Removing project files")
		filter "system:windows"
			os.rmdir("./.vs")
			os.remove("**.sln")
			os.remove("**.vcxproj*")

	end
}