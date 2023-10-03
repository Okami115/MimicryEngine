#pragma once
#include "Entities/Entity2D.h"
#include "Engine/Renderer.h"

class MimicryEngine_API Shape : public Entity2D
{
private:


public:
	Shape(Renderer* renderer);
	Shape();
	~Shape();

};

