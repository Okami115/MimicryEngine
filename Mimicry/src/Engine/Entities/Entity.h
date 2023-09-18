#pragma once
#include "Engine/Renderer.h"

class Entity
{
private:
	Renderer* renderer;


public:
	Entity(Renderer* renderer);
	~Entity();
};