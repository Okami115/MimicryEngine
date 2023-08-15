#include "../include/glfw3.h"
#include "Window.h"

Window window;

int main(void)
{
    window.CreateWindow();

    /* Loop until the user closes the window */
    while (!window.WindowShouldClose())
    {
        window.SwapBuffers();
        window.PollEvents();
    }

    glfwTerminate();
    return 0;
}