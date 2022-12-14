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
		Utility::Log("SDL did not initialize properly.", Utility::Severity::Failed);
		return 0;
	}
	
	window = SDL_CreateWindow("OpenGL", positionx, positiony, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	
	
	int contextInt = contextInit * 10;
	int majorNumber = contextInt / 10;
	int minorNumber = contextInt % 10 ;
	//std::cout << "Major Version " << majorNumber << std::endl;
	//std::cout << "Minor Version " << minorNumber << std::endl;
	

	//set OpenGL context and profile using values asssigned earlier
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, majorNumber);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minorNumber);


	if (!window)
	{
		Utility::Log("OpenGL Window was not created properly.", Utility::Severity::Failed);
		return false;
	}

	context = SDL_GL_CreateContext(window);

	if (!context)
	{
		Utility::Log("OpenGL context could not be created.", Utility::Severity::Failed);
		Utility::Log("The context is either invalid or not supported by your graphics card", Utility::Severity::Failed);
		
	}

	if (!gladLoaderLoadGL())
	{
		Utility::Log("Failed gladLoaderLoadGL", Utility::Severity::Failed);
		return false;
	}

	Utility::Log("Context has loaded succesfully!", Utility::Severity::Success);
	Utility::VersionDisplay();
	return true;
}

void Screen::Refresh()
{
	glClear(GL_COLOR_BUFFER_BIT);
}
void Screen::SwapBuffer()
{
	SDL_GL_SwapWindow(window);
}

void Screen::ClearColor()
{
	glClearColor(1.0f, 0.5f, 0.1f, 1.0f); //Change the background Color here (ORANGE)
}

void Screen::Shutdown()
{
	SDL_GL_DeleteContext;
	SDL_DestroyWindow;
	SDL_Quit;
}
