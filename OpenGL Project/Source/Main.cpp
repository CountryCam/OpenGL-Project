//#include <Windows.h>
//#include <gl/GL.h>

#include "Header/Utility.h"
#include <iostream>
#include <math.h>
#include <SDL.h>
#include "Header/Screen.h"
#include "Header/Input.h"
#include "Header/Shader.h"


bool isAppRunning { true };
Shader shader;
GLuint VBO{ 0 };

int main(int argc, char* argv[])
{
	Utility::Initialize();
	Screen::Instance()->Initialize(1280, 720, 20, 80, 4.5);
	Shader::Initialize();
	shader.Create("./OpenGL Project/Shader/Main.vert", "./OpenGL Project/Shader/Main.frag");
	shader.Use();
	//Karsten Code for Shader to complete myself
	GLfloat VBOData[] = { -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
						   0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
						  -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f,
						  -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f,
						   0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
						   0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f };

	auto vertexAttributeID = shader.GetAttributeID("vertexIn");
	auto colorAttributeID = shader.GetAttributeID("colorIn");

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(VBOData), VBOData, GL_STATIC_DRAW);

	glVertexAttribPointer(vertexAttributeID, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), 0);
	glVertexAttribPointer(colorAttributeID, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));

	glEnableVertexAttribArray(vertexAttributeID);
	glEnableVertexAttribArray(colorAttributeID);

	auto time = 0.0f;
	auto timeID = shader.GetUniformID("time");
	//Karsten Code for Shader to complete myself
		while (isAppRunning)
		{
			Input::Instance()->Update();
			Screen::Instance()->ClearColor();
			Screen::Instance()->Refresh();
			Screen::Instance()->SwapBuffer();
			/////////////////////////////////////////
			if (Input::Instance()->IsXClicked())
			{
				isAppRunning = false;
			}
			/////////////////////////////////////////

		}
		shader.Destroy();
		Shader::Shutdown();
		Screen::Instance()->Shutdown();
	
	return 0;
}
		
//glBegin(GL_TRIANGLES);
//
//glColor3f(1.0f, 0.0f, 0.0f);
//glVertex3f(0.0f, 0.5f, 0.0f);
//
//glColor3f(0.0f, 1.0f, 0.0f);
//glVertex3f(0.5f, -0.5f, 0.0f);
//
//glColor3f(0.0f, 0.0f, 1.0f);
//glVertex3f(-0.5f, -0.5f, 0.0f);
//
//glEnd();