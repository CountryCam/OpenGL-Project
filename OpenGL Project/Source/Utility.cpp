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

	SetConsoleTextAttribute(consoleHandle, static_cast<WORD>(severity)); //Upwork

}

void Utility::VersionDisplay()
{
	
}

