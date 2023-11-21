#include "InputManager.h"
#include "Engine/Window.h"

InputManager::InputManager(Window* window)
{
	this->window = window->GetWindowPtr();
}

InputManager::~InputManager()
{

}

bool InputManager::GetKeyDown(GLFWkeyfun key)
{
	return glfwSetKeyCallback(window, key) == GLFW_RELEASE;
}

bool InputManager::GetKey(GLFWkeyfun key)
{
	return glfwSetKeyCallback(window, key) == GLFW_RELEASE;
}

bool InputManager::GetKeyUp(GLFWkeyfun key)
{
	return glfwSetKeyCallback(window, key) == GLFW_RELEASE;
}