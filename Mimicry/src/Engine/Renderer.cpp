#include "Renderer.h"
#include "GLEW/glew.h"
#include "../include/glfw3.h"
#include <iostream>


Renderer::Renderer()
{
	
}

Renderer::~Renderer()
{
}

void Renderer::GenBufferObjects(unsigned int& buffer, int bufferID)
{
	glGenBuffers(bufferID, &buffer);
}

void Renderer::GenVAO(unsigned int& buffer, int bufferID)
{
	glGenVertexArrays(buffer, &buffer);
}

void Renderer::LoadVertexData(unsigned int& VAO,unsigned int& VBO, float* vertices, int verticesSize)
{
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * verticesSize, vertices, GL_STATIC_DRAW);
}

void Renderer::LoadIndexData(unsigned int& EBO, unsigned int* indices, int indicesSize)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(float) * indicesSize, indices, GL_STATIC_DRAW);
}

void Renderer::LoadVertexAttributes(unsigned int& VAO, unsigned int& VBO, float* vertices)
{
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

void Renderer::CreateShaderProgram(unsigned int& shaderProgram)
{
	shaderProgram = glCreateProgram();
}

void Renderer::InitVertexShader(const char* shaderSource,unsigned int& vertexShader, int vertexAttributeSize, unsigned int& shaderProgram)
{
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &shaderSource, NULL);
	glCompileShader(vertexShader);

	CompileErrorCheck(vertexShader);

	glAttachShader(shaderProgram, vertexShader);

	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
}

void Renderer::InitFragmentShader(const char* shaderSource, unsigned int& fragmentShader, unsigned int& shaderProgram)
{
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &shaderSource, NULL);
	glCompileShader(fragmentShader);

	CompileErrorCheck(fragmentShader);

	glAttachShader(shaderProgram, fragmentShader);

	glLinkProgram(shaderProgram);

	glDeleteShader(shaderProgram);

}

void Renderer::ClearFrame()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::DrawEntity2D(unsigned int& shaderProgram, unsigned int& VAO)
{
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Renderer::CompileErrorCheck(unsigned int& shader)
{
	int  success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::" << shader << "::COMPILATION_FAILED" << '\n' << infoLog << std::endl;
	}
	else
	{
		std::cout << "SHADER::" << shader << "::COMPILATION_SUCCESSFUL\n" << std::endl;
	}
}
