#include "BaseGame/BaseGame.h"
#include "glfw3.h"
#include "Engine/Shape.h"

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
		Shape myShape = Shape(&renderer);
		Init();

		while (!window.WindowShouldClose())
		{
			renderer.ClearFrame();
			myShape.DrawShape();
			window.SwapBuffers();
			window.PollEvents();
			Update();

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