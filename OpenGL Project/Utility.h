#pragma once
#include"glad.h"
#include<iostream>
#include<string>
//#include<Windows.h>
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


};