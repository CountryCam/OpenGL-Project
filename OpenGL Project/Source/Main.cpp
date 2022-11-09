//#include <Windows.h>
//#include <gl/GL.h>

#include "Header/Utility.h"
#include <iostream>
#include <SDL.h>
#include "Header/Screen.h"
#include "Header/Input.h"
#include "Header/Shader.h"


bool isAppRunning { true };
Shader shader;


int main(int argc, char* argv[])
{
	Screen::Instance()->Initialize(1280, 720, 20, 80, 4.5);
	Shader::Initialize();
	shader.Create("Main.vert", "Main.frag");

		while (isAppRunning)
		{
			Input::Instance()->Update();
			Screen::Instance()->Clear();
			Screen::Instance()->SwapBuffer();

			/*glBegin(GL_TRIANGLES); 

			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.5f, 0.0f);

			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(0.5f, -0.5f, 0.0f);

			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(-0.5f, -0.5f, 0.0f);

			glEnd();*/
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
		