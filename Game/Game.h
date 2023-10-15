#include "BaseGame/BaseGame.h"
#include "Engine/Shapes/Triangle.h"
#include "Engine/Shapes/Rectangle.h"


class MyGame : public BaseGame
{

	Triangle* triangle;
	Rectangle* rectangle;
	float trianglePosX = 0.005;
	float triangleRotarion = 1.0f;
	float triangleScale = 0.01f;

public:
	MyGame();
	~MyGame();

	void Init() override;
	void Update() override;
	void Deinit() override;
};