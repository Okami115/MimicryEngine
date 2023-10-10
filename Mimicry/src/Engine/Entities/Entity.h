#pragma once
#include "Engine/Renderer.h"

class MimicryEngine_API Entity
{
protected:
	Renderer* renderer;


public:
	Entity(Renderer* renderer);
	Entity();
	//Crear estas funciones junto con renderer
	void GetPos();
	void SetPos(int x, int y, int z);
	void GetScale();
	void SetScale(float x, float y, float z);
	void GetRotation();
	void SetRotation(int x, int y, int z);
	void SetColor(float r, float g, float b, float a);
	~Entity();
};