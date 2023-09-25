#include "BaseGame/BaseGame.h"
#include "Engine/Shapes/Triangle.h"

class MyGame : public BaseGame
{
	Triangle triangle = NULL;

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
	triangle.Translate(glm::vec3(-0.4f, -0.5f, 0.0f));
	triangle.Scale(glm::vec3(0.8f, 0.7f, 1.0f));
	triangle.Rotate(70.0f, glm::vec3(0.0f, 0.0f, 1.0f));
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