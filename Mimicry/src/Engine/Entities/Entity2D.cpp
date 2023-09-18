#include "Entity2D.h"

Entity2D::Entity2D(Renderer* renderer) : Entity(renderer)
{
	vertices = new float[12]{
		0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f,  -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f
	};

	indices = new unsigned int[6]{
		0, 1, 3,
		1, 2, 3
	};

	renderer->CreateShaderProgram(shaderProgram);
	renderer->InitVertexShader(vertexShaderSource, vertexShader, vertexAttributeSize, shaderProgram);
	renderer->InitFragmentShader(fragmentShaderSource, fragmentShader, shaderProgram);

	renderer->GenVAO(VAO, 1);
	renderer->GenBufferObjects(VBO, 1);
	renderer->GenBufferObjects(EBO, 1);
	renderer->LoadVertexData(VAO, VBO, vertices, 12);
	renderer->LoadIndexData(EBO, indices, 6);
	renderer->LoadVertexAttributes(VAO, VBO, vertices);
}

Entity2D::~Entity2D()
{

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
	//this->vertices = vertices;
}

void Entity2D::SetIndices(unsigned int indices[])
{
	//this->indices = indices;
}


void Entity2D::Draw2D()
{
	renderer->DrawEntity2D(shaderProgram, VAO);
}