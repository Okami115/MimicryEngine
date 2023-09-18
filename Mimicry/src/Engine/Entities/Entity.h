#pragma once
#include "Engine/Renderer.h"

class Entity
{
protected:
	Renderer* renderer;


public:
	Entity(Renderer* renderer);
	~Entity();
};