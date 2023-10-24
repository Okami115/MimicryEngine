#pragma once
#include "Exports.h"
#include <glm/gtc/matrix_transform.hpp>


class MimicryEngine_API Renderer
{
private:
#pragma region FRAGMENT SHADER
	const char* fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(0.0f, 0.0f, 1.0f, 1.0f);\n"
		"}\0";
#pragma endregion

#pragma region VERTEX SHADER
	const char* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"uniform mat4 MVP;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = MVP * vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";
#pragma endregion

	unsigned int VAO;	//Vertex Array object, stores vertex attributes
	unsigned int VBO;	//Vertex buffer object, stores vertices data
	unsigned int EBO;	//Element Buffer Objects, stores indices to specify to OpenGL what vertices t draw

	unsigned int vertexShader;
	unsigned int fragmentShader;

	unsigned int shaderProgram;

public:
	Renderer();
	~Renderer();

	void Init();
	void LoadVertexData(float* vertices, int verticesSize);
	void LoadIndexData(unsigned int* indices, int indicesSize);
	void LoadVertexAttributes(float* vertices);

	void CreateShaderProgram();
	void InitVertexShader();
    void InitFragmentShader();

	void GenBufferObjects();
	void GenVAO();

	void TranslatePosition(glm::mat4& translation, glm::vec3 newPos);
	void Rotate(glm::mat4& rotation, float angleInDegrees, glm::vec3 axis);
	void Scale(glm::mat4& scale, glm::vec3 scaler);

    void ClearFrame();

	void DrawEntity2D(glm::mat4x4& entityModel);

    void CompileErrorCheck(unsigned int& shader);
};