#pragma once
#include "Engine/Window.h"
#include "Engine/Renderer.h"

class __declspec(dllexport) BaseGame
{
protected:
	Window window;
	Renderer renderer;
	const char* title = "Mimicry Engine";

	virtual void Init();
	virtual void Update();
	virtual void Deinit();
	
public:
	void Run();
	BaseGame();
	~BaseGame();
};

