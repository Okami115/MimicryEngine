#include "Sprite.h"
#include <iostream>


Sprite::Sprite(Renderer* renderer, float frameDuration) : Entity2D(renderer)
{
	verticesSize = 36;
	indicesSize = 6;

	float vertex[]
	{
		// X,	 Y,	   Z,	 R,    G,	 B,	   A,	 U,    V,
		0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, //Top Derecha
		0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,//Bot Derecha
		-0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,//Bot Izquierda	
		-0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f// Top Izquierda
	};


	unsigned int index[]
	{
		0,1,3,
		1,2,3
	};

	animation = new Animation(frameDuration);

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
	renderer->DrawSprite(model, texture->texture2D, VAO);
}

void Sprite::AddFrame(UV uv0, UV uv1, UV uv2, UV uv3)
{
	animation->AddFrame(uv0, uv1, uv2, uv3);
}

void Sprite::SetSprite(std::string path)
{
	texture = new Texture(path);
	texture->LoadTexture(path);
}