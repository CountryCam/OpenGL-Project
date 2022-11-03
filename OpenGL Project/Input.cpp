#include "Input.h"
#include <glm.hpp>


Input* Input::Instance()
{
	static Input* input = new Input;
	return input;
}

bool Input::IsXClicked() const
{
	return isxclicked;
}

bool Input::IsKeyPressed() const
{
	return iskeypressed;
}

char Input::GetKey() const
{
	return 0;
}

char Input::GetKeyDown() const
{
	return 0;
}

bool Input::IsLeftButtonClicked() const
{
	return false;
}

bool Input::IsRightButtonClicked() const
{
	return false;
}

bool Input::IsMiddleButtonClicked() const
{
	return false;
}

const glm::ivec2& Input::GetMouseWheel() const
{
	return mouseWheel;
}

const glm::ivec2& Input::GetMousePosition() const
{
	// TODO: insert return statement here
	return mousePosition;
}

const glm::ivec2& Input::GetMouseMotion() const
{
	// TODO: insert return statement here
	return mouseMotion;
}

void Input::Update()
{
	while (SDL_PollEvent(&events))
	{
		switch (events.type)
		{
		case SDL_KEYUP:
		{
			//a key is pressed
			key;
			break;
		}

		case SDL_KEYDOWN:
		{
			//a key is released
			key;
			break;
		}

		case SDL_MOUSEBUTTONDOWN:
		{
			switch (events.button.button)
			{
			case SDL_BUTTON_LEFT:
			{
				//Left Button Clicked
				break;
			}
			case SDL_BUTTON_RIGHT:
			{
				//Right Button Clicked
				break;
			}
			case SDL_BUTTON_MIDDLE:
			{
				//Middle Button Clicked
				break;
			}


			}
		}
	}
}
}
