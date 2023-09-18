#include "Shape.h"

Shape::Shape(Renderer* renderer)
{
	vertices = new float[12] {
	0.5f, 0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	-0.5f,  -0.5f, 0.0f,
	-0.5f, 0.5f, 0.0f
	};

	indices = new unsigned int[6] {
		0, 1, 3,
		1, 2, 3
	};

	this->renderer = renderer;

	renderer->CreateShaderProgram(shaderProgram);
	renderer->InitVertexShader(vertexShaderSource, vertexShader, vertexAttributeSize, shaderProgram);
	renderer->InitFragmentShader(fragmentShaderSource, fragmentShader, shaderProgram);

	renderer->GenVAO(VAO, 1);
	renderer->GenBufferObjects(VBO, 1);
	renderer->GenBufferObjects(EBO, 1);
	renderer->LoadVertexData(VAO, VBO, vertices);
	renderer->LoadIndexData(EBO, indices);
	renderer->LoadVertexAttributes(VAO, VBO, vertices);
	
}

Shape::~Shape()
{

}

const char* Shape::GetVertexShaderSrc()
{
	return vertexShaderSource;
}

const char* Shape::GetFragmentShaderSrc()
{
	return fragmentShaderSource;
}

void Shape::SetVertices(float vertices[])
{
	//this->vertices = vertices;
}

void Shape::SetIndices(unsigned int indices[])
{
	//this->indices = indices;
}

void Shape::DrawShape()
{
	renderer->DrawShape(shaderProgram, VAO);
}