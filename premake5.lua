workspace "Checkers"

    configurations {
        "Debug",
        "Release"
    }

    startproject "Checkers"

outputdir = "%{cfg.buildcfg}.%{cfg.system}.%{cfg.architecture}"

include "CheckersModel"
include "CheckersRenderer"
