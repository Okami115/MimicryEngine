#include "Game.h"
#include "BaseGame/BaseGame.h"
#include "Engine/Shapes/Rectangle.h"

<<<<<<< HEAD
class MyGame : public BaseGame
{
<<<<<<< HEAD
	Triangle triangle = NULL;
	float trianglePosX = 0.005; 
	float triangleRotarion = 1.0f;
	float triangleScale = 0.01f;
=======
	Rectangle triangle = NULL;
>>>>>>> Input-Manager

public:
	MyGame();
	~MyGame();

	void Init() override;
	void Update() override;
	void Deinit() override;
};

=======
>>>>>>> Tomas
MyGame::MyGame() : BaseGame()
{

}

MyGame::~MyGame()
{

}

void MyGame::Init()
{
<<<<<<< HEAD
	float vertex[]
	{
		-1.2f, 0.5f, 0.0f,
		-0.2f, 0.5f, 0.0f,
		-0.2f, -0.5f, 0.0f
=======

	// Definirlo en la entity 2D
	float shapeVertices[12] = {
0.5f, 0.5f, 0.0f,
0.5f, -0.5f, 0.0f,
-0.5f,  -0.5f, 0.0f,
-0.5f, 0.5f, 0.0f
>>>>>>> Tomas
	};

	unsigned int index[]
	{
		0,1,2
	};

<<<<<<< HEAD

	triangle.SetVertices(vertex);
	triangle.SetIndices(index);
=======
	triangle = Rectangle(&renderer);


	// hacer uso de los getters y setters
	triangle.SetVertices(shapeVertices);
	triangle.SetIndices(shapeIndices);
>>>>>>> Input-Manager
	triangle.Init();
}

void MyGame::Update()
{

	triangle.Translate(glm::vec3(0.0f + trianglePosX, 0.0f, 0.0f));
	triangle.Scale(glm::vec3(1.0f- triangleScale, 1.0f - triangleScale, 1.0f));
	triangle.Rotate(-triangleRotarion, glm::vec3(0.0f, 0.0f, 1.0f));

	triangle.Draw2D();
}

void MyGame::Deinit()
{

}

