#include "BaseGame/BaseGame.h"
#include "Engine/Shapes/Rectangle.h"

class MyGame : public BaseGame
{
	Rectangle triangle = NULL;

public:
	MyGame();
	~MyGame();

	void Init() override;
	void Update() override;
	void Deinit() override;
};