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
		Shape myShape = Shape();
		renderer.InitShape(myShape);
		renderer.InitRenderer();
		Init();

		while (!window.WindowShouldClose())
		{
			renderer.ClearFrame();
			renderer.RenderFrame();
			window.SwapBuffers();
			window.PollEvents();
			Update();

		}
	}


	Deinit();
	glfwTerminate();

	if (createdWindow)
	{
		renderer.InitRenderer();
		Init();

		Shape* shapessdss = new Shape();
		renderer.InitShape(*shapessdss);

		while (!window.WindowShouldClose())
		{
			renderer.ClearFrame();
			renderer.RenderFrame();
			//Update();
			window.SwapBuffers();
			window.PollEvents();
		}
		Deinit();
		delete shapessdss;
	}


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