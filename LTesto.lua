--|---------------------------------------------
--| LTesto
--|---------------------------------------------
project "LTesto"
    location "Source"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "On"

	targetdir (TargetDirectory)
	objdir (IntermediateDirectory)

    files { 
        "%{prj.location}/LTesto/Core/*.h",
        "%{prj.location}/LTesto/Core/*.cpp",

        "%{prj.location}/LTesto/Runtime/*.h",
        "%{prj.location}/LTesto/Runtime/*.cpp",

        "%{wks.location}/LkEngine/Test/Suite/**.h",
        "%{wks.location}/LkEngine/Test/Suite/**.cpp",
   	}
    
    includedirs {
        "%{prj.location}",

		"%{wks.location}/LkEngine",
		"%{wks.location}/LkEngine/Source",

		"%{ExternalDirectory}",
        "%{Dependency.Glfw.IncludeDir}",
        "%{Dependency.Glad.IncludeDir}",
        "%{Dependency.StbImage.IncludeDir}",
        "%{Dependency.Spdlog.IncludeDir}",
        "%{Dependency.ImGui.IncludeDir}",
		"%{Dependency.ImGui.IncludeDir}/imgui", -- Allow 'imgui.h' as well as 'imgui/imgui.h' as an include.
        "%{Dependency.ImGuizmo.IncludeDir}",
        "%{Dependency.ImGuiNodeEditor.IncludeDir}",
        "%{Dependency.Assimp.IncludeDir}",
        "%{Dependency.Entt.IncludeDir}",
        "%{Dependency.Glm.IncludeDir}",
        "%{Dependency.Box2D.IncludeDir}",
        "%{Dependency.YamlCpp.IncludeDir}",
        "%{Dependency.Assimp.IncludeDir}",
        "%{Dependency.Tracy.IncludeDir}",
    }

    links {
        "LkEngine"
    }

    prebuildcommands {
        "{ECHO} [%{prj.name}] Starting build"
    }

	filter "system:windows"
		systemversion "latest"
        defines { "LK_PLATFORM_WINDOWS" }

	filter "system:linux"
        defines { "LK_PLATFORM_LINUX" }

	filter "configurations:AutomationTest"
		kind "ConsoleApp"
		symbols "On"
		runtime "Debug"

    filter { "configurations:not AutomationTest" }
        kind "None"
