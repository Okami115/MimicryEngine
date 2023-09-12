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

void Renderer::InitRenderer()
{
	shaderProgram = glCreateProgram();
}

void Renderer::InitShape(Shape& shape)
{
	glGenBuffers(1, &shape.VBO);
	glBindBuffer(GL_ARRAY_BUFFER, shape.VBO);

	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), shape.vertices, GL_STATIC_DRAW);

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, shape.VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 12, shape.vertices , GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 6, shape.indices, GL_STATIC_DRAW);

	InitVertexShader(shape);

	InitFragmentShader(shape);

	glAttachShader(shaderProgram, shape.vertexShader);
	glAttachShader(shaderProgram, shape.fragmentShader);
	glLinkProgram(shaderProgram);

	glUseProgram(shaderProgram);

	glDeleteShader(shape.vertexShader);
	glDeleteShader(shape.fragmentShader);
}

void Renderer::InitVertexShader(Shape& shape)
{
	const char* shaderSource = shape.GetVertexShaderSrc();

	shape.vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(shape.vertexShader, 1, &shaderSource, NULL);
	glCompileShader(shape.vertexShader);

	CompileErrorCheck(shape.vertexShader);
}

void Renderer::InitFragmentShader(Shape& shape)
{
	const char* shaderSource = shape.GetFragmentShaderSrc();
	shape.fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(shape.fragmentShader, 1, &shaderSource, NULL);
	glCompileShader(shape.fragmentShader);

	CompileErrorCheck(shape.fragmentShader);
}

void Renderer::ClearFrame()
{

}

void Renderer::RenderFrame()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	
}

void Renderer::RenderShape(Shape shape)
{

}

void Renderer::CompileErrorCheck(unsigned int shader)
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
