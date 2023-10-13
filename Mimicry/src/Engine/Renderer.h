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

public:
	Renderer();
	~Renderer();

	void Init();
	void LoadVertexData(unsigned int& VAO, unsigned int& VBO, float* vertices, int verticesSize);
	void LoadIndexData(unsigned int& EBO, unsigned int* indices, int indicesSize);
	void LoadVertexAttributes(unsigned int& VAO, unsigned int& VBO, float* vertices);

	void CreateShaderProgram(unsigned int& shaderProgram);
	void InitVertexShader(const char* shaderSource, unsigned int& vertexShader, int vertexAttributeSize, unsigned int& shaderProgram);
    void InitFragmentShader(const char* shaderSource, unsigned int& fragmentShader, unsigned int& shaderProgram);

	void GenBufferObjects(unsigned int& buffer, int bufferID);
	void GenVAO(unsigned int& buffer, int bufferID);

	void TranslatePosition(glm::mat4& translation, glm::vec3 newPos);
	void Rotate(glm::mat4& rotation, float angleInDegrees, glm::vec3 axis);
	void Scale(glm::mat4& scale, glm::vec3 scaler);

    void ClearFrame();

	void DrawEntity2D(unsigned int& shaderProgram, unsigned int& VAO, glm::mat4x4& entityModel);

    void CompileErrorCheck(unsigned int& shader);
};