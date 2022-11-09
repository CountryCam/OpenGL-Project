#pragma once
#include <iostream>
#include <SDL.h>
#include <glm.hpp>

typedef const Uint8* KeyState;

class Input
{
public:
	static Input* Instance();
	
	bool IsXClicked() const;
	bool IsKeyPressed() const;
	bool IsWindowFullScreen() const;

	char GetKeyUp() const;
	char GetKeyDown() const;


	bool IsLeftButtonClicked() const;
	bool IsRightButtonClicked() const;
	bool IsMiddleButtonClicked() const;

	const glm::ivec2& GetMouseWheel() const;
	const glm::ivec2& GetMouseMotion() const;
	const glm::ivec2& GetMousePosition() const;

	KeyState GetKeyStates() const;

	void Update();

private:
	SDL_Event events;

	Input() {}
	Input(const Input&);
	Input& operator = (const Input&);

	bool isXClicked = { false };
	bool isKeyPressed = { false };
	bool isWindowFullScreen = { false };

	char keyUp{ 0 };
	char keyDown{ 0 };
	
	bool isleftbuttonclicked = { false };
	bool isrightbuttonclicked = { false };
	bool ismiddlebuttonclicked = { false };
	
	bool quit = { false };
	
	glm::ivec2 mouseWheel{ 0 };
	glm::ivec2 mouseMotion{ 0 };
	glm::ivec2 mousePosition{ 0 };

	KeyState keyStates{ nullptr };
};

