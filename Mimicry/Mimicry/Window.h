#pragma once

class Window
{
private:

public:
	Window();
	~Window();
	GLFWwindow* CreateWindow();
	void SwapBuffers(GLFWwindow* windowPtr);
	void PollEvents();
};
