#include "../include/glfw3.h"
#include "Window.h"

Window window;

int main(void)
{
    GLFWwindow* windowPtr;

    windowPtr = window.CreateWindow();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(windowPtr))
    {
        window.SwapBuffers(windowPtr);
        window.PollEvents();
    }

    glfwTerminate();
    return 0;
}