#include "InputManager.h"
#include "Engine/Window.h"

InputManager::InputManager(Window* window)
{
	this->window = window->GetWindowPtr();
}

InputManager::~InputManager()
{

}

bool InputManager::GetKeyDown(int key)
{
	return glfwGetKey(window, key) == GLFW_PRESS;
}

bool InputManager::GetKey(int key)
{
	return glfwGetKey(window, key) == GLFW_PRESS;
}

bool InputManager::GetKeyUp(int key)
{
	return glfwGetKey(window, key) == GLFW_PRESS;
}