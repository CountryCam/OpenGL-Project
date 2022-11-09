#pragma once
#include<glad.h>
#include<Windows.h>
#include<iostream>
#include<string>

//#include<gl\GL.h>
//#include<glext.h>


class Utility
{
public:
	enum class Severity
	{
		Default = 5,
		Warning = 14,
		Falied = 12
	};

	static void Initialize();
	static void VersionDisplay();
private:

	static HANDLE consoleHandle;
};