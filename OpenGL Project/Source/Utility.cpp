#include "Header/Utility.h"

HANDLE Utility::consoleHandle{ nullptr };

void Utility::Initialize()
{
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Utility::VersionDisplay()
{
	
}

void Utility::Log(const std::string& outputMsg, Severity severity)
{

}
