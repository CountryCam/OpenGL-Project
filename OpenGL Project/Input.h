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

	const glm::ivec2& GetMouseWheel() const;
	const glm::ivec2& GetMouseMotion() const;
	const glm::ivec2& GetMousePosition() const;


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
	
	glm::ivec2 mouseWheel{ 0 };
	glm::ivec2 mouseMotion{ 0 };
	glm::ivec2 mousePosition{ 0 };

};

	//Keyboard keyboard
	//Mouse mouse

