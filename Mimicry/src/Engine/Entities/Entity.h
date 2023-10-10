#pragma once
#include "Engine/Renderer.h"

class MimicryEngine_API Entity
{
protected:
	Renderer* renderer;


public:
	Entity(Renderer* renderer);
	Entity();
	~Entity();
};