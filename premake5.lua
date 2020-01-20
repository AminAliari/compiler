workspace "Project"
	architecture "x64"
	startproject "Compiler"

	configurations
	{
		"Debug",
		"Release",
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Compiler"
	location "Compiler"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.l",
		"%{prj.name}/src/**.y",
	}

	includedirs
	{
		"%{prj.name}/src",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"_CRT_SECURE_NO_DEPRECATE",
		"_CRT_NONSTDC_NO_DEPRECATE",
	}

	prebuildcommands
	{
		"call \"$(SolutionDir)build-flex.bat\" \"$(ProjectDir)src\\\"",
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"