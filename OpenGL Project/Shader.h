#pragma once
#include <fstream>
#include"Utility.h"
#include<string>


class Shader
{
public:
	
	static bool Initialize();
	static void Shutdown();

	bool Create(const std::string& vertexfilename, 
		const std::string& fragmentfilename);

	void Use() const;
	void Destroy() const;

private:
	bool LinkProgram();
	bool CompileShaders(const std::string& filename);

	static GLint vertexShaderID;
	static GLint fragmentShaderID;


	GLuint ProgramID{ 0 };
};