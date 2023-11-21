#include "Entity.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../Mimicry/Utility.h"

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

void Entity::SetScale(float x, float y, float z)
{
	scale = glm::scale(scale, { x, y, z });

	UpdateModel();
}
void Entity::SetRotation(float angle)
{
	rotation = glm::rotate(rotation, glm::radians(angle), glm::vec3(0, 0, 1));
	UpdateModel();
}

void Entity::SetColor(float r, float g, float b, float a)
{

	UpdateModel();
}

void Entity::GetPos(){}
void Entity::GetScale(){}
void Entity::GetRotation(){}

Entity::~Entity()
{

}

void Entity::Init()
{
	renderer->GenVAO(VAO);
	renderer->GenBufferObjects(VBO, EBO);

	renderer->LoadVertexData(vertices, verticesSize, VAO, VBO);
	renderer->LoadIndexData(indices, indicesSize, EBO);
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
	renderer->DrawEntity2D(model, VAO);
}