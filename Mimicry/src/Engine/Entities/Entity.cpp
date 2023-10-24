#include "Entity.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

Entity::Entity(Renderer* renderer)
{
	this->renderer = renderer;
}

Entity::Entity()
{

}

void Entity::SetPos(int x, int y, int z)
{
	translation = glm::translate(translation, { x, y, z });

	UpdateModel();
}

Entity::~Entity()
{

}

void Entity::Init()
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

void Entity::SetVertices(float vertices[])
{
	this->vertices = vertices;
}

void Entity::SetIndices(unsigned int indices[])
{
	this->indices = indices;
}

void Entity::Translate(glm::vec3 newPos)
{
	renderer->TranslatePosition(translation, newPos);
	UpdateModel();
}

void Entity::Rotate(float angleInDegrees, glm::vec3 axis)
{
	renderer->Rotate(rotation, angleInDegrees, axis);
	UpdateModel();
}

void Entity::Scale(glm::vec3 newScale)
{
	renderer->Scale(scale, newScale);
	UpdateModel();
}

void Entity::UpdateModel()
{
	model = translation * rotation * scale;
}

void Entity::Draw2D()
{
	renderer->DrawEntity2D(model);
}