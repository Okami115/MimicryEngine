#pragma once
#include "Engine/Window.h"
#include "Engine/Renderer.h"

class BaseGame
{
private:
	Window window;
	Renderer renderer;

protected:
	virtual void Init();
	virtual void Update();
	virtual void Deinit();
	
public:
	void Run();
	BaseGame();
	~BaseGame();


};

