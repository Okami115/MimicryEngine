#include "Rectangle.h"

Rectangle::Rectangle(Renderer* renderer) : Shape(renderer)
{
	verticesSize = 12;
	indicesSize = 6;

	float vertex[]
	{
		0.5f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f
	};


	unsigned int index[]
	{
		0,1,2,
		0,1,3
	};


	SetVertices(vertex);
	SetIndices(index);
	Init();
}

Rectangle::~Rectangle()
{

}