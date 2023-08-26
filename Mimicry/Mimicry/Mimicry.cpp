#include "GLEW/glew.h"
#include "Window.h"
#include "Renderer.h"
#include "glfw3.h"

int main(void)
{
	Window window;
	Renderer renderer;
	const char* title = "Mimicry Engine";

	bool createdWindow = window.CreateWindow(800, 600, title);

	if (createdWindow)
	{
		renderer.InitRenderer();

		/* Loop until the user closes the window */
		while (!window.WindowShouldClose())
		{
			renderer.ClearFrame();
			renderer.RenderFrame();
			window.SwapBuffers();
			window.PollEvents();

		}
	}



	glfwTerminate();

	return 0;
}