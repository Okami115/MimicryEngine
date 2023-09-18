#include "Rectangle.h"

Rectangle::Rectangle(Renderer* renderer) : Shape(renderer)
{
	verticesSize = 12;
	indicesSize = 6;
}

Rectangle::~Rectangle()
{

}