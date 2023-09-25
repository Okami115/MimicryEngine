#include "Renderer.h"
#include "GLEW/glew.h"
#include "../include/glfw3.h"
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

Renderer::Renderer()
{
	
}

Renderer::~Renderer()
{
}

void Renderer::Init()
{
	//projection = glm::ortho(-10.0f, 800.0f, 0.0f, 600.0f, 0.0f, 100.0f);
	//view = glm::lookAt(
	//	glm::vec3(0, 0, 1),
	//	glm::vec3(0, 0, 0),
	//	glm::vec3(0, 1, 0)
	//);
	//model = glm::mat4(1.0f);
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

void Renderer::TranslatePosition(glm::mat4& translation, glm::vec3 newPos)
{
	glm::mat4 trans = glm::mat4(1.0f);
	trans = glm::translate(trans, newPos);
	translation = trans * translation;
}

void Renderer::Rotate(glm::mat4& rotation, float angleInDegrees, glm::vec3 axis)
{
	glm::mat4 trans = glm::mat4(1.0f);
	trans = glm::rotate(trans, glm::radians(angleInDegrees), axis);
	rotation = trans * rotation;
}

void Renderer::Scale(glm::mat4& scale, glm::vec3 scaler)
{
	glm::mat4 trans = glm::mat4(1.0f);
	trans = glm::scale(trans, scaler);
	scale = trans * scale;
}

void Renderer::ClearFrame()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::DrawEntity2D(unsigned int& shaderProgram, unsigned int& VAO, glm::mat4x4& entityModel) 
{
	glm::mat4x4 projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, 0.1f, 100.0f);
	glm::mat4x4 view = glm::lookAt(
		glm::vec3(0, 0, 1),
		glm::vec3(0, 0, 0),
		glm::vec3(0, 1, 0)
	);
	glUseProgram(shaderProgram);
	unsigned int transformLoc = glGetUniformLocation(shaderProgram, "transform");
	glm::mat4 newMVP = projection * view * entityModel;
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(entityModel));
	GLuint MatrixID = glGetUniformLocation(shaderProgram, "MVP");
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
