#pragma once
#include <fstream>
#include"Utility.h"


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
	static GLint vertexShaderID;
	static GLint fragmentShaderID;

	bool LinkProgram();
	bool CompileShaders(const std::string& filename);



	GLuint ProgramID{ 0 };
};