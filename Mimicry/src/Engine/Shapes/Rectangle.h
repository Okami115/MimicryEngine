#pragma once
#include "Engine/Shape.h"

class Rectangle : Shape
{
public:
	Rectangle(Renderer* renderer);
	~Rectangle();

	void DrawRectangle();

private:

};