#include "BaseGame/BaseGame.h"
#include "Engine/Shapes/Triangle.h"
#include "Engine/Shapes/Rectangle.h"

class MyGame : public BaseGame
{
	Triangle triangle = NULL;
	Rectangle rectangle = NULL;

public:
	MyGame();
	~MyGame();

	void Init() override;
	void Update() override;
	void Deinit() override;
};

MyGame::MyGame() : BaseGame()
{

}

MyGame::~MyGame()
{

}

void MyGame::Init()
{
	float shapeVertices[12] = {
0.5f, 0.5f, 0.0f,
0.5f, -0.5f, 0.0f,
-0.5f,  -0.5f, 0.0f,
-0.5f, 0.5f, 0.0f
	};


	unsigned int shapeIndices[6]{
		0, 1, 3,
		1,2,3
	};

	triangle.SetVertices(shapeVertices);
	triangle.SetIndices(shapeIndices);
	triangle.Init();

}

void MyGame::Update()
{

	triangle.Draw2D();
}

void MyGame::Deinit()
{

}

int main(void)
{
	MyGame myGame = MyGame();

	myGame.Run();
}