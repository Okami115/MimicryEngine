#pragma once
#include <string>;
#include "glfw3.h"
#include "Exports.h"

class MimicryEngine_API Window
{
private:
	GLFWwindow* windowPtr;

public:
	Window();
	~Window();
	GLFWwindow* GetWindowPtr();
	bool CreateWindow(int width, int height, const char* title);
	bool WindowShouldClose();
	void SwapBuffers();
	void PollEvents();
};
