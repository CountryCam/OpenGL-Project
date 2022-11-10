#include "Header/Shader.h"

GLint Shader::vertexShaderID = 0;
GLint Shader::fragmentShaderID = 0;

bool Shader::Initialize()
{
	
	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);

	if (vertexShaderID == 0)
	{
		Utility::Log("Error creating the vertex shader object."
			"Could be due to older version graphics card that does not support modern OpenGL.",
			Utility::Severity::Failed);
						
		return false;
	}

	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	if (fragmentShaderID == 0)
	{
		Utility::Log("Error creating the fragment shader object."
			"Could be due to older version graphics card that does not support modern OpenGL.",
			Utility::Severity::Failed);
		return false;
	}

	return true;
}

void Shader::Shutdown()
{
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);
}


bool Shader::Create(const std::string& vertexfilename, const std::string& fragmentfilename)
{
	//If the shader ProgramID is 0! it means the error has accured due to GLAD not being set up the correct way or the Graphics card is very old.
	ProgramID = glCreateProgram();

	if (ProgramID == 0)
	{
		Utility::Log("Error creating shader program. Possible causes could be a "
				"old graphics card",Utility::Severity::Failed);
		return false;
	}

	if (!CompileShaders(vertexfilename))
	{
		return false;
	}

	if (!CompileShaders(fragmentfilename))
	{
		return false;
	}

	if (!LinkProgram())
	{
		return false;
	}

	return true;
}

void Shader::Use() const
{
	glUseProgram(ProgramID);
}

void Shader::Destroy() const
{
	glDeleteProgram(ProgramID);
}

bool Shader::LinkProgram()
{
	glAttachShader(ProgramID, vertexShaderID);
	glAttachShader(ProgramID, fragmentShaderID);
	glLinkProgram(ProgramID);
	glDetachShader(ProgramID, vertexShaderID);
	glDetachShader(ProgramID, fragmentShaderID);

	GLint result = 0;
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &result);

	if (result == GL_FALSE)
	{
		GLchar error[1000];
		GLsizei bufferSize = 1000;
		glGetProgramInfoLog(ProgramID, bufferSize, &bufferSize, error);
		//Utility::Log(error, Utility::Severity::Failure);
		std::cout << "Failed" << std::endl;
		return false;
	}

	return true;
}

bool Shader::CompileShaders(const std::string& filename)
{
	std::ifstream file(filename, std::ios_base::in);

	if (!file.is_open())
	{
		Utility::Log("Error loading shader file \"" + (filename)+"\"."
			"Possible causes could be a corrupt or missing file. It could also be "
			"that the filename and/or path are incorrectly spelt.", Utility::Severity::Failed);
		
		return false;
	}

	std::string line;
	std::string sourceCode;

	while (!file.eof())
	{
		getline(file, line);
		sourceCode += line + "\n";

	}

	file.close();

	auto shaderID = (filename.find(".vert")) ? vertexShaderID : fragmentShaderID;

	const GLchar* finalCode = reinterpret_cast<const GLchar*>(sourceCode.c_str());
	glShaderSource(shaderID, 1, &finalCode, nullptr);
	glCompileShader(shaderID);

	GLint compileResult;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compileResult);

	if (compileResult == GL_FALSE)
	{
		GLchar error[1000];
		GLsizei bufferSize = 1000;
		glGetShaderInfoLog(shaderID, bufferSize, &bufferSize, error);
		Utility::Log(error, Utility::Severity::Failed);
		return false;
	}
	return true;
}


