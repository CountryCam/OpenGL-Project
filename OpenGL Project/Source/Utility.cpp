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

void Utility::CheckGLError()
{

}

void Utility::VersionDisplay()
{
	std::cout << glGetString(GL_VENDOR) << std::endl;
	std::cout << glGetString(GL_RENDERER) << std::endl;
	std::cout << glGetString(GL_VERSION) << std::endl;
	std::cout << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}

