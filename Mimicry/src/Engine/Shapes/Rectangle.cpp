#include "Rectangle.h"

Rectangle::Rectangle(Renderer* renderer) : Shape(renderer)
{
	verticesSize = 36;
	indicesSize = 6;

	float vertex[]
	{
		// X,	 Y,	   Z,	 R,    G,	 B,	   A,	 U,    V,
		0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		-0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f
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