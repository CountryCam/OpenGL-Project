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
		std::cout << "SDL did not initialize properly." << std::endl;
		return 0;
	}
	
	window = SDL_CreateWindow("OpenGL", positionx, positiony, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	
	
	int contextInt = contextInit * 10;
	int majorNumber = contextInt / 10;
	int minorNumber = contextInt % 10 ;
	std::cout << "Major Version " << majorNumber << std::endl;
	std::cout << "Minor Version " << minorNumber << std::endl;
	

	//set OpenGL context and profile using values asssigned earlier
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, majorNumber);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minorNumber);


	if (!window)
	{
		std::cout << "SDL window could not be created." << std::endl;
	}

	context = SDL_GL_CreateContext(window);

	if (!context)
	{
		std::cout << "OpenGL context could not be created. "
			"The context is either invalid or not supported by your graphics card" << std::endl;
		return 0;
	}

	if (!gladLoaderLoadGL())
	{
		std::cout << "Failed" << std::endl;
		return false;
	}
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

void Screen::Clear()
{
	system("cls");
}

void Screen::Shutdown()
{
	SDL_GL_DeleteContext;
	SDL_DestroyWindow;
	SDL_Quit;
}
