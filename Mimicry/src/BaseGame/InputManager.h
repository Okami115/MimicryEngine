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

	bool GetKeyDown(int key);
	bool GetKey(int key);
	bool GetKeyUp(int key);
};