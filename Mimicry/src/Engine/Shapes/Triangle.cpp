#include "Triangle.h"

Triangle::Triangle(Renderer* renderer) : Shape(renderer)
{
	verticesSize = 9;
	indicesSize = 3;
}

Triangle::~Triangle()
{

}