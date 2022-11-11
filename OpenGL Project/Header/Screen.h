#pragma once
#include "Header/gl.h"
//#include <Windows.h>
//#include <gl/GL.h>
#include"Utility.h"
#include <iostream>
#include <SDL.h>

class Screen
{

public:
	static Screen* Instance();

	// To get window to postion at the center of the screen you need to 1280 (width) * 0.25 (1/4 WindowsScreen)
	// Initialize the screen passing through the width, height, positionX, positionY, ContextInit is the version
	bool Initialize(int width, int height, int positionx, int positiony, float contextInit ); 
	void Refresh();
	void SwapBuffer();
	void Clear();
	void Shutdown();

	//SetClearColor(color);
private:
	Screen() {}
	Screen(const Screen&);
	Screen& operator = (const Screen&);

	SDL_Window* window{ nullptr };
	SDL_GLContext context{ nullptr };

	
};