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