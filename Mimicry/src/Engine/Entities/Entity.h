#pragma once
#include "Engine/Renderer.h"

class __declspec(dllexport)Entity
{
protected:
	Renderer* renderer;


public:
	Entity(Renderer* renderer);
	Entity();
	~Entity();
};