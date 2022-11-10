#include "Header/Utility.h"

HANDLE Utility::consoleHandle{ nullptr };

void Utility::Initialize()
{
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Utility::Log(const std::string& outputMsg, Severity severity)
{
	//Did consoleHandle get called check?
	assert(consoleHandle);

	SetConsoleTextAttribute(consoleHandle, static_cast<WORD>(severity)); 
	std::cout << outputMsg << std::endl;
	SetConsoleTextAttribute(consoleHandle, static_cast<WORD>(Severity::Default));

}

void Utility::VersionDisplay()
{
	std::cout << glGetString(GL_VENDOR) << std::endl;
	std::cout << glGetString(GL_RENDERER) << std::endl;
	std::cout << glGetString(GL_VERSION) << std::endl;
	std::cout << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}

void Utility::CheckGLError()
{
	GLenum errorValue = glGetError();

	if (errorValue == GL_NO_ERROR)
	{
		Log("Old function fixed code is working! No error has been detected!", Utility::Severity::Success);
	}

	else if (errorValue == GL_INVALID_ENUM)
	{
		Log("Old function fixed code isn't working! An invalid enum has been detected! The code was ignored!", Utility::Severity::Failed);
	}

	else if (errorValue == GL_INVALID_VALUE)
	{
		Log("Old function fixed code isn't working! An invalid number has been detected because it's out of range! The code was ignored!", Utility::Severity::Failed);
	}

	else if (errorValue == GL_INVALID_OPERATION)
	{
		Log("Old function fixed code isn't working! An invalid operation has been detected! The code was ignored!", Utility::Severity::Failed);
	}

	else if (errorValue == GL_INVALID_FRAMEBUFFER_OPERATION)
	{
		Log("Old function fixed code isn't working! The framebuffer object is not complete! The code was ignored!", Utility::Severity::Failed);
	}

	else if (errorValue == GL_OUT_OF_MEMORY)
	{
		Log("Old function fixed code isn't working! There is nor enough memory left to run it!", Utility::Severity::Failed);
	}

	else if (errorValue == GL_STACK_UNDERFLOW)
	{
		Log("Old function fixed code isn't working, and has caused the stack to underflow!", Utility::Severity::Failed);
	}

	else if (errorValue == GL_STACK_OVERFLOW)
	{
		Log("Old function fixed code isn't working, and has caused the stack to overflow!", Utility::Severity::Failed);
	}
}


