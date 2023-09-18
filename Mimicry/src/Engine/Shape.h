#pragma once
#include "Entity.h"
#include "Renderer.h"

class Shape : Entity
{
private:
#pragma region FRAGMENT SHADER
	const char* fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\0";
#pragma endregion

#pragma region VERTEX SHADER
	const char* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";
#pragma endregion

    Renderer* renderer;

public:
	unsigned int VBO;	//Vertex buffer object, wherever we can we try to send as much data as possible at once

	unsigned int vertexShader;
	unsigned int fragmentShader;

	unsigned int shaderProgram;

	float* vertices;

	int vertexAttributeSize = 3; 
	unsigned int* indices;


	Shape(Renderer* renderer);
	~Shape();

	const char* GetVertexShaderSrc();
	const char* GetFragmentShaderSrc();

	void SetVertices(float vertices[]);
	void SetIndices(unsigned int indices[]);

	void DrawShape();
};

