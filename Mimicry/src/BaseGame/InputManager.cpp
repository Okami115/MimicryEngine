#include "InputManager.h"

InputManager::InputManager(GLFWwindow* window)
{
	this->window = window;
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
	glfwSetKeyCallback(window, key) == GLFW_RELEASE;
}

bool InputManager::GetKeyUp(GLFWkeyfun key)
{
	glfwSetKeyCallback(window, key) == GLFW_RELEASE;
}