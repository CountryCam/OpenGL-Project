#pragma once
#include <iostream>
#include <SDL.h>
#include <glm.hpp>

class Input
{
public:
	static Input* Instance();
	
	bool IsXClicked() const;
	bool IsKeyPressed() const;

	char GetKey() const;
	char GetKeyDown() const;


	bool IsLeftButtonClicked() const;
	bool IsRightButtonClicked() const;
	bool IsMiddleButtonClicked() const;

	int GetMouseWheelMotion() const;

	const SDL_Point& GetMousePosition() const;
	const SDL_Point& GetMouseMotion() const;

	void Update();

private:
	SDL_Event events;

	Input() {}
	Input(const Input&);
	Input& operator = (const Input&);

	bool isxclicked = { false };
	bool iskeypressed = { false };

	
	char key = events.key.keysym.sym;
	
	bool isleftbuttonclicked = { false };
	bool isrightbuttonclicked = { false };
	bool ismiddlebuttonclicked = { false };
	
	bool quit = { false };

};

	//Keyboard keyboard
	//Mouse mouse

