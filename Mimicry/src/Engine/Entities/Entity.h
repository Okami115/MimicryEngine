#pragma once
#include "Engine/Renderer.h"

class MimicryEngine_API Entity
{
public:
	// mover a Entity.cpp
	glm::mat4x4 model;
	glm::mat4 translation;
	glm::mat4 rotation;
	glm::mat4 scale;


	float* vertices;
	int verticesSize;

	int vertexAttributeSize = 3;
	unsigned int* indices;
	int indicesSize;

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
	void SetRotation(float angle);
	void SetColor(float r, float g, float b, float a);

	void Init();

	void SetVertices(float vertices[]);
	void SetIndices(unsigned int indices[]);

	void Translate(glm::vec3 newPos);
	void Rotate(float angleInDegrees, glm::vec3 axis);
	void Scale(glm::vec3 newScale);

	void UpdateModel();
	virtual void Draw2D();
	~Entity();
};