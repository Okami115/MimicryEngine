#pragma once
#include "Engine/Exports.h"
#include "Engine/Window.h"
#include "Engine/Renderer.h"
#include <BaseGame/InputManager.h>

class MimicryEngine_API BaseGame
{
protected:
	Window* window;
	Renderer* renderer;
	const char* title = "Mimicry Engine";

	virtual void Init();
	virtual void Update();
	virtual void Deinit();
	
public:
	InputManager* input;
	void Run();
	BaseGame();
	~BaseGame();
};

