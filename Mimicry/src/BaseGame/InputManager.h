#pragma once
#include"glfw3.h"

class InputManager
{
private:
	GLFWwindow* window;
public:
	InputManager(GLFWwindow* window);
	~InputManager();

	bool GetKeyDown(GLFWkeyfun key);
	bool GetKey(GLFWkeyfun key);
	bool GetKeyUp(GLFWkeyfun key);
};