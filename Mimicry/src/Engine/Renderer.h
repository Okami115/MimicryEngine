#pragma once
#include "Exports.h"
#include <glm/gtc/matrix_transform.hpp>


class MimicryEngine_API Renderer
{
private:
#pragma region FRAGMENT SHADER
	const char* fragmentShaderSource = R"(#version 330 core
in vec4 vertexColor;
in vec2 TexCoord;
out vec4 FragColor;

uniform vec3 color = vec3(1.0f, 1.0f, 1.0f);
uniform float alpha = 1.0f;
uniform float useTexture = 0.0f;
uniform sampler2D theTexture;

void main()
{
	if (useTexture == 0.0f)
		FragColor = vec4(vertexColor * vec4(color,alpha));
	else
		FragColor = texture(theTexture, TexCoord) * vec4(vertexColor * vec4(color, alpha));

})";

#pragma endregion

#pragma region VERTEX SHADER
	const char* vertexShaderSource = R"(#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec4 aColor;
layout(location = 2) in vec2 tex;

uniform mat4 MVP;

out vec4 vertexColor;
out vec2 TexCoord;
void main()
{
	gl_Position = MVP * vec4(aPos.x, aPos.y, aPos.z, 1.0);
    TexCoord = vec2(tex.x, tex.y);
    vertexColor = vec4(aColor.x, aColor.y, aColor.z, 1.0);
})";
#pragma endregion


	unsigned int vertexShader;
	unsigned int fragmentShader;

	unsigned int shaderProgram;

	glm::mat4x4 view;
	glm::mat4x4 projection;

public:
	Renderer();
	~Renderer();

	void Init();
	void LoadVertexData(float* vertices, int verticesSize, unsigned int& VAO, unsigned int& VBO);
	void LoadIndexData(unsigned int* indices, int indicesSize, unsigned int EBO);
	void LoadVertexAttributes(float* vertices);

	void CreateShaderProgram();
	void CreateVecBuffer(float* vertices, unsigned int* indices, int verticesSize, int indicesSize, int atribVertexSize, unsigned int& VAO, unsigned int& VBO, unsigned int& EBO);
	void InitVertexShader();
    void InitFragmentShader();

	void GenBufferObjects(unsigned int& VBO, unsigned int& EBO);
	void GenVAO(unsigned int& VAO);

	void TranslatePosition(glm::mat4& translation, glm::vec3 newPos);
	void Rotate(glm::mat4& rotation, float angleInDegrees, glm::vec3 axis);
	void Scale(glm::mat4& scale, glm::vec3 scaler);

    void ClearFrame();

	void DrawEntity2D(glm::mat4x4& entityModel, unsigned int& VAO);

	void DrawSprite(glm::mat4x4& entityModel, unsigned int& texture, unsigned int& VAO);

	void CompileErrorCheck(unsigned int& shader);
};