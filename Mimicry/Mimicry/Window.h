#pragma once
#include <string>;
#include "glfw3.h"

class Window
{
private:
	GLFWwindow* windowPtr;

public:
	Window();
	~Window();
	bool CreateWindow(int width, int height, const char* title);
	bool WindowShouldClose();
	void SwapBuffers();
	void PollEvents();
};
