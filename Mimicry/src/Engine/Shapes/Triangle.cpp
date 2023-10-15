#include "Triangle.h"

Triangle::Triangle(Renderer* renderer) : Shape(renderer)
{
	verticesSize = 9;
	indicesSize = 3;

	float vertex[]
	{
		0.0f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f
	};


	unsigned int index[]
	{
		0,1,2
	};


	SetVertices(vertex);
	SetIndices(index);
	Init();
}

Triangle::~Triangle()
{

}