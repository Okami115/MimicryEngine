#pragma once
#include"glfw3.h"

class InputManager
{
private:
	GLFWwindow* window;
public:
	InputManager(GLFWwindow* window);
	~InputManager();

	void GetKeyDown();
	void GetKey();
	void GetKeyUp();
};