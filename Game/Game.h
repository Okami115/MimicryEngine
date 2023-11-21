#include "BaseGame/BaseGame.h"
#include "Engine/Shapes/Triangle.h"
#include "Engine/Shapes/Rectangle.h"
#include "../Mimicry/Mimicry/Sprite.h"


class MyGame : public BaseGame
{

	Sprite* background;
	Sprite* obstacle;
	Sprite* Sonic;

	int sonicSpeed;
	vec3 sonicPos;

public:
	MyGame();
	~MyGame();

	void Init() override;
	void Update() override;
	void Deinit() override;
	void CheckInputs();
};