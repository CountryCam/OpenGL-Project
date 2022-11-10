#include "Header/Screen.h"


Screen* Screen::Instance()
{
	static Screen* screen = new Screen;
	return screen;
}

bool Screen::Initialize(int width, int height, int positionx, int positiony, float contextInit)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) == -1)
	{
		Utility::Log("SDL did not initialize properly.",Utility::Severity::Failed);
		return 0;
	}
	
	
	
	int contextInt = contextInit * 10;
	int majorNumber = contextInt / 10;
	int minorNumber = contextInt % 10 ;
	std::cout << "Major Version " << majorNumber << std::endl;
	std::cout << "Minor Version " << minorNumber << std::endl;
	

	//set OpenGL context and profile using values asssigned earlier
	//SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, majorNumber);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minorNumber);

	window = SDL_CreateWindow("OpenGL", positionx, positiony, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

	if (!window)
	{
		Utility::Log("SDL window could not be created.",Utility::Severity::Failed);
		return false;
	}

	context = SDL_GL_CreateContext(window);
	

	if (!context)
	{
		while (!context)
		{
			Utility::Log("OpenGL context could not be created.", Utility::Severity::Warning);
			Utility::Log("The context is either invalid or not supported by your graphics card", Utility::Severity::Warning);
		}
		
		Utility::VersionDisplay();
		Utility::Log("Failed to load ");

		return false;
	}

	if (!gladLoaderLoadGL())
	{
		Utility::Log("Failed glad LoaderGL", Utility::Severity::Failed);
		return false;
	}
	Utility::Log("Screen Successfully run! Displaying Information below:", Utility::Severity::Success);
	return true;
}

void Screen::Refresh()
{
	glClear(GL_COLOR_BUFFER_BIT); //Clearing the Buffer
}
void Screen::SwapBuffer()
{
	SDL_GL_SwapWindow(window);
}

void Screen::Clear()
{
	system("cls");
}

void Screen::Shutdown()
{
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit;
}
