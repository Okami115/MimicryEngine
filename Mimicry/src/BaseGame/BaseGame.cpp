#include "../BaseGame/BaseGame.h"


BaseGame::BaseGame()
{
}

BaseGame::~BaseGame()
{
}

void BaseGame::Run()
{
	bool createdWindow = window.CreateWindow(800, 600, title);

	if (createdWindow)
	{
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