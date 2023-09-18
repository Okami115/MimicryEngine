#pragma once
#include "Engine/Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(Renderer* renderer);
	~Rectangle();

	void DrawRectangle();

private:

};