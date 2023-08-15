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
       

        /* Swap front and back buffers */
        glfwSwapBuffers(windowPtr);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}