#include "Shape.h"

Shape::Shape()
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