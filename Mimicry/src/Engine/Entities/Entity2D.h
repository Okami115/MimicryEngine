#pragma once
#include "Entity.h"
#include "glm/glm.hpp"

class MimicryEngine_API Entity2D : public Entity
{
public:
	glm::mat4x4 model;
	glm::mat4 translation;
	glm::mat4 rotation;
	glm::mat4 scale;


	// mover a renderer
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
		"uniform mat4 transform;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = transform * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";
#pragma endregion

	unsigned int VBO;	//Vertex buffer object, stores vertices data
	unsigned int VAO;	//Vertex Array object, stores vertex attributes
	unsigned int EBO;	//Element Buffer Objects, stores indices to specify to OpenGL what vertices t draw

	unsigned int vertexShader;
	unsigned int fragmentShader;

	unsigned int shaderProgram;

	float* vertices;
	int verticesSize;

	int vertexAttributeSize = 3;
	unsigned int* indices;
	int indicesSize;


public:
	Entity2D(Renderer* renderer);
	Entity2D();
	~Entity2D();

	void Init();

	const char* GetVertexShaderSrc();
	const char* GetFragmentShaderSrc();
	void SetVertexShaderSrc(char* source);
	void SetFragmentShaderSrc(char* source);

	void SetVertices(float vertices[]);
	void SetIndices(unsigned int indices[]);

	void Translate(glm::vec3 newPos);
	void Rotate(float angleInDegrees, glm::vec3 axis);
	void Scale(glm::vec3 newScale);

	void UpdateModel();
	virtual void Draw2D();

};