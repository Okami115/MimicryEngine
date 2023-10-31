#include "Sprite.h"
#include <iostream>


Sprite::Sprite(Renderer* renderer) : Entity2D(renderer)
{
	verticesSize = 32;
	indicesSize = 8;

	float vertex[]
	{
		// X,	 Y,	   Z,	 R,    G,	 B,	   A,	 U,    V,
		0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 
		-0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f
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

Sprite::Sprite()
{

}

Sprite::~Sprite()
{

}

void Sprite::SetSprite(std::string path)
{
	if (texture != NULL)
	{
		texture->LoadTexture(path);
	}
	else
	{
		texture = new Texture(path);
	}

}