#include "../include/glfw3.h"
#include "Window.h"

int main(void)
{
	Window window;
	const char* title = "Mimicry Engine";

	bool createdWindow = window.CreateWindow(800, 600, title);

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