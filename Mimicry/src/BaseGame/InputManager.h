#pragma once
#include"glfw3.h"
#include "Engine/Window.h"

class InputManager
{
private:
	GLFWwindow* window;
public:
	InputManager(Window* window);
	~InputManager();

	bool GetKeyDown(GLFWkeyfun key);
	bool GetKey(GLFWkeyfun key);
	bool GetKeyUp(GLFWkeyfun key);
};