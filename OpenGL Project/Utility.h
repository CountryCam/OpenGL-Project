#pragma once
#include<iostream>
#include<Windows.h>
#include<string>



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
private:


};