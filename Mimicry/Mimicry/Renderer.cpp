#include "Renderer.h"
#include "GLEW/glew.h"
#include "../include/glfw3.h"


Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::RenderFrame()
{
	/* Render here */
	glClear(GL_COLOR_BUFFER_BIT);
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

}