#include "Game.h"
#include "BaseGame/BaseGame.h"
#include "Engine/Shapes/Triangle.h"

MyGame::MyGame() : BaseGame()
{

}

MyGame::~MyGame()
{

}

void MyGame::Init()
{

	triangle = new Triangle(renderer);

	float vertex[]
	{
		0.5f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f
	};


	unsigned int index[]
	{
		0,1,2
	};


	triangle->SetVertices(vertex);
	triangle->SetIndices(index);


	// hacer uso de los getters y setters

	triangle->Init();
	
}

void MyGame::Update()
{

	//triangle.Translate(glm::vec3(0.0f + trianglePosX, 0.0f, 0.0f));
	//triangle.Scale(glm::vec3(1.0f- triangleScale, 1.0f - triangleScale, 1.0f));
	//triangle.Rotate(-triangleRotarion, glm::vec3(0.0f, 0.0f, 1.0f));

	triangle->Draw2D();
}

void MyGame::Deinit()
{
	delete(triangle);
}

