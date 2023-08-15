#include "../include/glfw3.h"
#include "Window.h"

int main(void)
{
	Window window;
	bool createdWindow = window.CreateWindow();

	if (createdWindow)
	{
		/* Loop until the user closes the window */
		while (!window.WindowShouldClose())
		{
			window.SwapBuffers();
			window.PollEvents();
		}
	}

	glfwTerminate();
	return 0;
}