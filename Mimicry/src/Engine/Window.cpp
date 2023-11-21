#include "GLEW/glew.h"
#include "Window.h"
#include "glfw3.h"
#include <string>
#include <iostream>

Window::Window()
{

}

Window::~Window()
{

}

GLFWwindow* Window::GetWindowPtr()
{
    return windowPtr;
}

bool Window::CreateWindow(int width, int height, const char* title)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return false;


    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return false;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        std::cout << "Error!" << std::endl;

    

    windowPtr = window;

    return true;
}

bool Window::WindowShouldClose()
{
    return glfwWindowShouldClose(windowPtr);
}

void Window::SwapBuffers()
{
    /* Swap front and back buffers */
    glfwSwapBuffers(windowPtr);
}

void Window::PollEvents()
{
    /* Poll for and process events */
    glfwPollEvents();
}