#include "BaseGame/BaseGame.h"
#include "Engine/Shapes/Triangle.h"


class MyGame : public BaseGame
{

	Triangle* triangle;
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