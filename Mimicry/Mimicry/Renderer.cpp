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
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), vertices, GL_STATIC_DRAW);

	InitVertexShader();
	
	InitFragmentShader();
}

void Renderer::InitVertexShader()
{
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	CompileErrorCheck(vertexShader);
}

void Renderer::InitFragmentShader()
{
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	CompileErrorCheck(fragmentShader);
}

void Renderer::ClearFrame()
{

}

void Renderer::RenderFrame()
{
	/* Render here */
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLES, 0, 3);
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
