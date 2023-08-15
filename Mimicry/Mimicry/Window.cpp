#include "../include/glfw3.h"
#include "Window.h"

Window::Window()
{

}

Window::~Window()
{

}

GLFWwindow* Window::CreateWindow()
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return nullptr;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return nullptr;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    return window;
}

void Window::SwapBuffers(GLFWwindow* windowPtr)
{
    /* Swap front and back buffers */
    glfwSwapBuffers(windowPtr);
}

void Window::PollEvents()
{
    /* Poll for and process events */
    glfwPollEvents();
}