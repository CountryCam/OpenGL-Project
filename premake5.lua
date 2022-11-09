workspace "OpenGl Project"

	-- These lines define where the exes, objects, and buildlogs are made. targetdir means target directory, and if you follow the path you'll find your exe, no matter if debug or release.
	targetdir "./Build/bin/%{cfg.buildcfg}/%{cfg.platform}/"
	objdir "./Build/obj/%{cfg.buildcfg}/%{cfg.platform}/"
	buildlog "./Build/obj/%{cfg.platform}/%{cfg.buildcfg}/%{prj.name}.log"

	-- project settings, better to keep it the same.
	largeaddressaware "on"
	editandcontinue "off"
	staticruntime "on"

	-- systemversion defines windows SDK, currently set to latest (vs2022), character set defines which characterset you use, such as unicode or ascii. warnings set to extra help give you warnings if premake fails (and gives some).
	systemversion "latest"
	characterset "unicode"
	warnings "extra"

	-- premake flags
	flags {
		"shadowedvariables", -- Warn when a variable, type declaration, or function is shadowed. Check out what that is here https://en.wikipedia.org/wiki/Variable_shadowing
		"multiprocessorcompile", -- Enable Visual Studio to use multiple compiler processes when building.
		"undefinedidentifiers", -- Warn if an undefined identifier is evaluated in an #if directive.
	}

	platforms {
		"Win-x86", -- sets the project to 32 bits
	}

	configurations {
		"Release", -- configurations for release
		"Debug", -- configurations for debug
	}

	--x86
	filter "platforms:Win-x86"
		architecture "x86" -- sets the platform we wrote earlier to 32 bits.
	--end

	-- sets the release filter
	filter "Release"
		defines "NDEBUG"
		optimize "full"
		runtime "release"
		symbols "off"

	-- sets the debug filter
	filter "Debug"
		defines "DEBUG"
		optimize "debug"
		runtime "debug"
		symbols "on"

	-- sets the project and targetfolder name, project language, c++ dialect, and warnings for the project.
	project "Cams OpenGL Project"
		targetname "Cam's OpenGL Project"
		language "c++"
		cppdialect "c++20"
		warnings "off"

	-- sets the type of program, ours is consoleapp in this work.
		kind "consoleapp"

	-- sets the dll and lib folder locations
		filter "platforms:Win-x86"
			syslibdirs {
			".\\DevLib\\SDL\\lib\\",
			".\\DevLib\\SDL\\dlls\\",
			
			}
		filter {}

	-- defines the libraries it uses, you need to add opengl32 if you use OpenGL
		links {
			"SDL2",
			"SDL2main",
			"opengl32",
		}
		
	-- sets include directories for the headers and sourse files.
		includedirs {
			".\\DevLib\\SDL\\include\\",
			".\\OpenGL Project\\",
			".\\DevLib\\SDL\\glm\\glm\\",
		}

	-- sets where it gets source files.
		files {
			".\\OpenGL Project\\**",
			".\\**.md",
			".\\**.lua",
			".\\**.gitignore",
		}

	-- makes virtual paths, these are all from the source file folder, and you can set extensions for it.
		vpaths {
   			--["Headers"] = {"**.h", "**.hpp"},
   			--["Sources"] = {"**.c", "**.cpp"},
   			["Docs"] = {"**.txt", "**.md", "**.lua", "**.gitignore"}
			--["Shaders"] = {"**.frag", "**.vert"}
		}

	-- postbuildcommand to automatically copy dlls from their folder to the build folder, if you change any of these, make sure to change the filepath here.
	postbuildcommands{ 
		{"{COPY} ./DevLib/SDL/dlls/**.dll ./Build//bin//%{cfg.buildcfg}//%{cfg.platform}//"}
	}