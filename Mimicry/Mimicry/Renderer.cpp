#include "Renderer.h"
#include "GLEW/glew.h"
#include "../include/glfw3.h"


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