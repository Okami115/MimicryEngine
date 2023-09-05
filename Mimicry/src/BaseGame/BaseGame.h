#pragma once
#include "../Engine/Window.h"
#include "../Engine/Renderer.h"

class BaseGame
{
private: 
	Window window;
	Renderer renderer;
	const char* title = "Mimicry Engine";

protected:
	virtual void Init();
	virtual void Update();
	virtual void Deinit();

	
public:
	BaseGame();
	~BaseGame();

	void Run();
};

