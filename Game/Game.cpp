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

	sprite = new Sprite(renderer, 1);
	sprite->SetPos(400, 300, 0);
	sprite->SetScale(500, 500, 0);
	sprite->SetSprite("../Assets/messi.png");
	//sprite->AddFrame(UV(0.5f, 0.5f), UV(0.5f, 0), UV(0, 0), UV(0, 0.5f));
	//sprite->AddFrame(UV(1, 1), UV(1, 0.5f), UV(0.5f, 0.5f), UV(0.5f, 1));
}

void MyGame::Update()
{
	//triangle->Draw2D();
	//rectangle->Draw2D();
	sprite->Draw2D();
}

void MyGame::Deinit()
{
	delete(triangle);
	delete(rectangle);
	delete(sprite);
}

