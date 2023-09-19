#include "BaseGame/BaseGame.h"
#include "glfw3.h"
#include "Engine/Shapes/Rectangle.h"
#include "Engine/Shapes/Triangle.h"

BaseGame::BaseGame()
{
}

BaseGame::~BaseGame()
{
}

void BaseGame::Run()
{
	const char* title = "Mimicry Engine";

	bool createdWindow = window.CreateWindow(800, 600, title);

	if (createdWindow)
	{
		Init();

		while (!window.WindowShouldClose())
		{
			renderer.ClearFrame();
			Update();
			window.SwapBuffers();
			window.PollEvents();
		}
	}

	Deinit();
	glfwTerminate();

}

void BaseGame::Init()
{

}

void BaseGame::Update()
{

}

void BaseGame::Deinit()
{

}