#pragma once

class Window
{
private:
	GLFWwindow* windowPtr;

public:
	Window();
	~Window();
	bool CreateWindow();
	bool WindowShouldClose();
	void SwapBuffers();
	void PollEvents();
};
