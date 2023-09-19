#pragma once
#include "Engine/Exports.h"
#include "Engine/Window.h"
#include "Engine/Renderer.h"

class MimicryEngine_API BaseGame
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
	void Run();
	BaseGame();
	~BaseGame();
};

