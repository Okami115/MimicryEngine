#include "Entity2D.h"

Entity2D::Entity2D(Renderer* renderer) : Entity(renderer)
{

}

Entity2D::~Entity2D()
{

}

void Entity2D::Init()
{
	renderer->CreateShaderProgram(shaderProgram);
	renderer->InitVertexShader(vertexShaderSource, vertexShader, vertexAttributeSize, shaderProgram);
	renderer->InitFragmentShader(fragmentShaderSource, fragmentShader, shaderProgram);

	renderer->GenVAO(VAO, 1);
	renderer->GenBufferObjects(VBO, 1);
	renderer->GenBufferObjects(EBO, 1);
	renderer->LoadVertexData(VAO, VBO, vertices, verticesSize);
	renderer->LoadIndexData(EBO, indices, indicesSize);
	renderer->LoadVertexAttributes(VAO, VBO, vertices);
}

const char* Entity2D::GetVertexShaderSrc()
{
	return vertexShaderSource;
}

const char* Entity2D::GetFragmentShaderSrc()
{
	return fragmentShaderSource;
}

void Entity2D::SetVertexShaderSrc(char* source)
{
	vertexShaderSource = source;
}

void Entity2D::SetFragmentShaderSrc(char* source)
{
	fragmentShaderSource = source;
}

void Entity2D::SetVertices(float vertices[])
{
	this->vertices = vertices;
}

void Entity2D::SetIndices(unsigned int indices[])
{
	this->indices = indices;
}

void Entity2D::Draw2D()
{
	renderer->DrawEntity2D(shaderProgram, VAO);
}