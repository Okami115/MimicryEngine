#pragma once
#include "Exports.h"
#include <glm/gtc/matrix_transform.hpp>


class MimicryEngine_API Renderer
{
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