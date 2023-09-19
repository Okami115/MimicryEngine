#pragma once
#include "Entities/Entity2D.h"
#include "Engine/Renderer.h"

class __declspec(dllexport) Shape : public Entity2D
{
private:


public:
	Shape(Renderer* renderer);
	~Shape();

};

