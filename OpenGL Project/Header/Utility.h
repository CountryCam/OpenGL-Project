#pragma once
#include<Header/gl.h>
#include<Windows.h>
#include<iostream>
#include<string>
#include<assert.h>
#
//#include<gl\GL.h>
//#include<glext.h>


class Utility
{
public:
	enum class Severity
	{
		Default = 5,
		Warning = 14,
		Falied = 4,
		Success = 10 
	};

	static void Initialize();
	static void VersionDisplay();
	static void Log(const std::string& outputMsg, Severity severity = Severity::Default);
	static void CheckGLError();

private:

	static HANDLE consoleHandle;
};