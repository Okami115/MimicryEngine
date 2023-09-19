#include "Triangle.h"

Triangle::Triangle(Renderer* renderer) : Entity2D(renderer)
{
	verticesSize = 9;
	indicesSize = 3;
}

Triangle::Triangle() : Entity2D()
{

}

Triangle::~Triangle()
{

}