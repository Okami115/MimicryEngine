#pragma once
#include "Entity.h"

class Entity2D : public Entity
{
protected:
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
	~Entity2D();

	void Init();

	const char* GetVertexShaderSrc();
	const char* GetFragmentShaderSrc();
	void SetVertexShaderSrc(char* source);
	void SetFragmentShaderSrc(char* source);

	void SetVertices(float vertices[]);
	void SetIndices(unsigned int indices[]);

	virtual void Draw2D();

};