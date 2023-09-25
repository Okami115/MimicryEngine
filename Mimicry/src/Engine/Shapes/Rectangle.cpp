#include "Rectangle.h"

Rectangle::Rectangle(Renderer* renderer) : Entity2D(renderer)
{
	verticesSize = 12;
	indicesSize = 6;
}

Rectangle::~Rectangle()
{

}