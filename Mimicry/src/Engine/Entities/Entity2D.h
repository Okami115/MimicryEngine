#pragma once
#include "Entity.h"
#include "glm/glm.hpp"

class MimicryEngine_API Entity2D : public Entity
{
public:
	// mover a Entity.cpp
	glm::mat4x4 model;
	glm::mat4 translation;
	glm::mat4 rotation;
	glm::mat4 scale;


	// mover a renderer


	float* vertices;
	int verticesSize;

	int vertexAttributeSize = 3;
	unsigned int* indices;
	int indicesSize;


public:
	Entity2D(Renderer* renderer);
	Entity2D();
	~Entity2D();

	void Init();

	const char* GetVertexShaderSrc();
	const char* GetFragmentShaderSrc();
	void SetVertexShaderSrc(char* source);
	void SetFragmentShaderSrc(char* source);

	void SetVertices(float vertices[]);
	void SetIndices(unsigned int indices[]);

	void Translate(glm::vec3 newPos);
	void Rotate(float angleInDegrees, glm::vec3 axis);
	void Scale(glm::vec3 newScale);

	void UpdateModel();
	virtual void Draw2D();

};