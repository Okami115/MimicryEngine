#pragma once

class Window
{
private:
	GLFWwindow* windowPtr;

public:
	Window();
	~Window();
	GLFWwindow* CreateWindow();
	bool WindowShouldClose();
	void SwapBuffers();
	void PollEvents();
};
