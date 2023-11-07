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

	//triangle = new Triangle(renderer);
	//rectangle = new Rectangle(renderer);
	//rectangle->SetPos(100,100,0);
	//rectangle->SetScale(100, 100, 0);
	sprite = new Sprite(renderer);
	sprite->SetPos(400, 300, 0);
	sprite->SetScale(500, 500, 0);
	sprite->SetSprite("../Assets/messi.png");
}

void MyGame::Update()
{

	//triangle.Translate(glm::vec3(0.0f + trianglePosX, 0.0f, 0.0f));
	//triangle.Scale(glm::vec3(1.0f- triangleScale, 1.0f - triangleScale, 1.0f));
	//triangle.Rotate(-triangleRotarion, glm::vec3(0.0f, 0.0f, 1.0f));

	//triangle->Draw2D();
	//rectangle->Draw2D();
	sprite->Draw2D();
}

void MyGame::Deinit()
{
	delete(triangle);
	delete(rectangle);
}

