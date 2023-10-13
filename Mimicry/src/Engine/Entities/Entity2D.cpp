#include "Entity2D.h"
#include <iostream>

Entity2D::Entity2D(Renderer* renderer) : Entity(renderer)
{

}

Entity2D::Entity2D() : Entity()
{

}

Entity2D::~Entity2D()
{

}

void Entity2D::Init()
{
	//mover a Entity.cpp 
	renderer->LoadVertexData(vertices, verticesSize);
	renderer->LoadIndexData(indices, indicesSize);
	renderer->LoadVertexAttributes(vertices);

	model = glm::mat4(1.0f);
	translation = glm::mat4(1.0f);
	scale = glm::mat4(1.0f);
	rotation = glm::mat4(1.0f);
}

void Entity2D::SetVertices(float vertices[])
{
	this->vertices = vertices;
}

void Entity2D::SetIndices(unsigned int indices[])
{
	this->indices = indices;
}

void Entity2D::Translate(glm::vec3 newPos)
{
	renderer->TranslatePosition(translation, newPos);
	UpdateModel();
}

void Entity2D::Rotate(float angleInDegrees, glm::vec3 axis)
{
	renderer->Rotate(rotation,angleInDegrees, axis);
	UpdateModel();
}

void Entity2D::Scale(glm::vec3 newScale)
{
	renderer->Scale(scale, newScale);
	UpdateModel();
}

void Entity2D::UpdateModel()
{
	std::cout << model[0][0];
	model = translation * rotation * scale;
	std::cout << model[0][0];
}

void Entity2D::Draw2D()
{
	renderer->DrawEntity2D(model);
}