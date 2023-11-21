#include "Renderer.h"
#include "../Mimicry/Utility.h"
#include "GLEW/glew.h"
#include "../include/glfw3.h"
#include <iostream>
#include <glm/gtc/type_ptr.hpp>
#include <fstream>
#include <sstream>

std::string ReadShader(std::string Path)
{
	std::string src;
	std::ifstream fShaderFile;

	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	fShaderFile.open(Path);

	try
	{
		if (fShaderFile.is_open())
		{
			std::stringstream fShaderStream;
			fShaderStream << fShaderFile.rdbuf();
			src = fShaderStream.str();
			fShaderFile.close();

		}
	}
	catch (std::ifstream::failure& e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}
	return src;

}

//----------------------INIT------------------------------

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::Init()
{
	projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, 0.1f, 100.0f);
	view = glm::lookAt(
		glm::vec3(0, 0, 1),
		glm::vec3(0, 0, 0),
		glm::vec3(0, 1, 0)
	);

	CreateShaderProgram();
	InitVertexShader();
	InitFragmentShader();
}

void Renderer::InitVertexShader()
{
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	CompileErrorCheck(vertexShader);

	glAttachShader(shaderProgram, vertexShader);

	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
}

void Renderer::InitFragmentShader()
{
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	CompileErrorCheck(fragmentShader);

	glAttachShader(shaderProgram, fragmentShader);

	glLinkProgram(shaderProgram);

	glDeleteShader(shaderProgram);

}

//---------------------CREATE----------------------------

void Renderer::CreateShaderProgram()
{
	shaderProgram = glCreateProgram();
}

void Renderer::CreateVecBuffer(float* vertices, unsigned int* indices, int verticesSize, int indicesSize, int atribVertexSize,
	unsigned int& VAO, unsigned int& VBO, unsigned int& EBO)
{
	GenVAO(VAO);
	GenBufferObjects(VBO, EBO);

	LoadVertexData(vertices, verticesSize, VAO, VBO);


	LoadIndexData(indices, indicesSize, EBO);

	glVertexAttribPointer(0, atribVertexSize, GL_FLOAT, GL_FALSE, atribVertexSize * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}

//---------------------GEN-------------------------------

void Renderer::GenBufferObjects(unsigned int& VBO, unsigned int& EBO)
{
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
}

void Renderer::GenVAO(unsigned int& VAO)
{
	glGenVertexArrays(1, &VAO);
}

//-------------------------LOAD----------------------------

void Renderer::LoadVertexData(float* vertices, int verticesSize, unsigned int& VAO, unsigned int& VBO)
{
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * verticesSize, vertices, GL_STATIC_DRAW);
	
}

void Renderer::LoadIndexData(unsigned int* indices, int indicesSize, unsigned int EBO)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(float) * indicesSize, indices, GL_STATIC_DRAW);
}

void Renderer::LoadVertexAttributes(float* vertices)
{
	//bindear los buffer para asignar los atributos del vertice
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(7 * sizeof(float)));
	glEnableVertexAttribArray(2);
}

//-----------------------TRS-------------------------------------

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

//-----------------------DRAW--------------------------------

void Renderer::ClearFrame()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::DrawEntity2D(glm::mat4x4& entityModel, unsigned int& VAO)
{
	glUseProgram(shaderProgram);

	glm::vec4 newColor = glm::vec4(0.0f, 1.0f, 0.0f, 1.0f);
	glUniform4f(glGetUniformLocation(shaderProgram, "FragColor"), newColor.x, newColor.y, newColor.z, newColor.w);
	glUniform1i(glGetUniformLocation(shaderProgram, "useTexture"), false);

	unsigned int MVP = glGetUniformLocation(shaderProgram, "MVP");
	glm::mat4 newMVP = projection * view * entityModel;
	glUniformMatrix4fv(MVP, 1, GL_FALSE, glm::value_ptr(newMVP));
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Renderer::DrawSprite(glm::mat4x4& entityModel, unsigned int& texture, unsigned int& VAO)
{
	unsigned int aux = glGetUniformLocation(shaderProgram, "useTexture");

	glUseProgram(shaderProgram);

	glUniform4f(glGetUniformLocation(shaderProgram, "FragColor"), 1, 1, 1, 1);
	glUniform1f(aux, 1.0f);

	unsigned int MVP = glGetUniformLocation(shaderProgram, "MVP");
	glm::mat4 newMVP = projection * view * entityModel;
	glUniformMatrix4fv(MVP, 1, GL_FALSE, glm::value_ptr(newMVP));
	glBindVertexArray(VAO);
	glBindTexture(GL_TEXTURE_2D, texture);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

//----------------------ERROR-------------------------------

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
