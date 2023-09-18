#include "BaseGame/BaseGame.h"
#include "glfw3.h"
#include "Engine/Shapes/Rectangle.h"

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

	float shapeVertices[12] = {
		0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f,  -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f
	};


	unsigned int shapeIndices[6]{
		0, 1, 3,
		1, 2, 3
	};

	if (createdWindow)
	{
		Rectangle* myShape = new Rectangle(&renderer);
		myShape->SetVertices(shapeVertices);
		myShape->SetIndices(shapeIndices);
		myShape->Init();
		Init();

		while (!window.WindowShouldClose())
		{
			renderer.ClearFrame();
			myShape->Draw2D();
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