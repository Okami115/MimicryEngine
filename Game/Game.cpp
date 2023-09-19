#include "BaseGame/BaseGame.h"

class MyGame : public BaseGame
{
	void Init() override;
	void Update() override;
	void Deinit() override;
};

void MyGame::Init()
{

}

void MyGame::Update()
{

}

void MyGame::Deinit()
{

}

int main(void)
{
	MyGame myGame;

	myGame.Run();
}