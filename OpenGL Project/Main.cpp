#include <Windows.h>
#include <gl/GL.h>

#include <iostream>
#include <SDL.h>
#include "Screen.h"
#include "Input.h"


bool isAppRunning { true };



int main(int argc, char* argv[])
{
	Screen::Instance()->Initialize(1280, 720, 320, 180, 4.5);

		while (isAppRunning)
		{
			Screen::Instance()->Clear();
			Screen::Instance()->SwapBuffer();

			glBegin(GL_TRIANGLES);

			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.5f, 0.0f);

			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(0.5f, -0.5f, 0.0f);

			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(-0.5f, -0.5f, 0.0f);

			glEnd();

		}
		
	Screen::Instance()->Shutdown();
	
	return 0;
}
		