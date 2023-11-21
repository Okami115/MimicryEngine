#include "Game.h"
#include "BaseGame/BaseGame.h"
#include "Engine/Shapes/Triangle.h"
#include <BaseGame/InputManager.cpp>
#include "../Mimicry/Mimicry/Time.h"

MyGame::MyGame() : BaseGame()
{

}

MyGame::~MyGame()
{

}

void MyGame::Init()
{
	background = new Sprite(renderer, 1);
	background->SetPos(400, 300, 0);
	background->SetScale(800, 600, 0);
	background->SetSprite("../Assets/background.jpg");

	obstacle = new Sprite(renderer, 1);
	obstacle->SetPos(100, 100, 0);
	obstacle->SetScale(49, 49, 0);
	obstacle->SetSprite("../Assets/Sonic_Mania_Sprite_Sheet - copia.png");

	Sonic = new Sprite(renderer, 1);
	sonicPos = vec3(200, 100, 0);
	Sonic->SetPos(sonicPos.x, sonicPos.y, sonicPos.z);
	Sonic->SetScale(41, 26, 0);
	Sonic->SetSprite("../Assets/Sonic_Mania_Sprite_Sheet - copia.png");
}

void MyGame::Update()
{
	CheckInputs();
	background->Draw2D();
	obstacle->Draw2D();
	Sonic->Draw2D();
}

void MyGame::Deinit()
{
	delete(background);
	delete(obstacle);
	delete(Sonic);
}

void MyGame::CheckInputs()
{
	if (input->GetKey(GLFW_KEY_A))
	{
		sonicPos.x = sonicPos.x + Time::DeltaTime();
		Sonic->SetPos(sonicPos.x, sonicPos.y, sonicPos.z);
	}

	if (input->GetKey(GLFW_KEY_D))
	{
		sonicPos.x = sonicPos.x - Time::DeltaTime();
		Sonic->SetPos(sonicPos.x, sonicPos.y, sonicPos.z);
	}
}

