#include "Sprite.h"
#include <iostream>


Sprite::Sprite(Renderer* renderer) : Entity2D(renderer)
{
	verticesSize = 36;
	indicesSize = 6;

	float vertex[]
	{
		// X,	 Y,	   Z,	 R,    G,	 B,	   A,	 U,    V,
		0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
		0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
		-0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f
	};


	unsigned int index[]
	{
		0,1,3,
		1,2,3
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

void Sprite::Draw2D()
{
	renderer->DrawSprite(model, texture->texture2D);
}

void Sprite::SetSprite(std::string path)
{
	texture = new Texture(path);
	texture->LoadTexture(path);
}