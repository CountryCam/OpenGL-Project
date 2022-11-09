#include "Header/Input.h"
#include <glm.hpp>


Input* Input::Instance()
{
	static Input* input = new Input;
	return input;
}

bool Input::IsXClicked() const
{
	return isXClicked;
}

bool Input::IsKeyPressed() const
{
	return isKeyPressed;
}

bool Input::IsWindowFullScreen() const
{
	return isWindowFullScreen;
}

char Input::GetKeyUp() const
{
	return keyUp;
}

char Input::GetKeyDown() const
{
	return keyDown;
}

bool Input::IsLeftButtonClicked() const
{
	return isleftbuttonclicked;
}

bool Input::IsRightButtonClicked() const
{
	return isrightbuttonclicked;
}

bool Input::IsMiddleButtonClicked() const
{
	return ismiddlebuttonclicked;
}

const glm::ivec2& Input::GetMouseWheel() const
{
	return mouseWheel;
}

const glm::ivec2& Input::GetMousePosition() const
{
	return mousePosition;
}

const glm::ivec2& Input::GetMouseMotion() const
{
	return mouseMotion;
}

KeyState Input::GetKeyStates() const
{
	return keyStates;
}

void Input::Update()
{
	SDL_Event events;
	keyStates = SDL_GetKeyboardState(nullptr);
	isXClicked = false;
	isWindowFullScreen = false;
	mouseWheel = glm::ivec2(0);
	mouseMotion = glm::ivec2(0);

	while (SDL_PollEvent(&events))
	{
		switch (events.type)
		{
		case SDL_WINDOWEVENT:
		{
			if (events.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
			{
				isWindowFullScreen = true;
			}
			break;
		}

		case SDL_QUIT:
		{
			isXClicked = true;
			break;
		}

		case SDL_KEYUP:
		{
			//a key is pressed
			isKeyPressed = false;
			keyUp =  events.key.keysym.sym;
			break;
		}

		case SDL_KEYDOWN:
		{
			//a key is released
			isKeyPressed = true;
			keyUp = events.key.keysym.sym;
			break;
		}

		case SDL_MOUSEMOTION:
		{
			mousePosition.x = events.motion.x;
			mousePosition.y = events.motion.y;
			mouseMotion.x = events.motion.xrel;
			mouseMotion.y = events.motion.yrel;
			break;
		}
		case SDL_MOUSEWHEEL:
		{
			mouseWheel.x = events.wheel.x;
			mouseWheel.y = events.wheel.y;
			break;
		}
		case SDL_MOUSEBUTTONUP:
		{
			switch (events.button.button)
			{
			case SDL_BUTTON_LEFT: { isleftbuttonclicked = false; break; }
			case SDL_BUTTON_RIGHT: { isrightbuttonclicked = false; break; }
			case SDL_BUTTON_MIDDLE: { ismiddlebuttonclicked = false; break; }
			}

			break;
		}
		case SDL_MOUSEBUTTONDOWN:
		{
			switch (events.button.button)
			{
			case SDL_BUTTON_LEFT: {  isleftbuttonclicked = true; break; }
			case SDL_BUTTON_RIGHT: {  isrightbuttonclicked = true; break; }
			case SDL_BUTTON_MIDDLE: { ismiddlebuttonclicked = true; break; }
			}
			break;
		}
	}
}
}
