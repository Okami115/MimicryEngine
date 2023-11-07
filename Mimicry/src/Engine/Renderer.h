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

uniform mat4 transform = mat4(1.0f);
uniform mat4 view = mat4(1.0f);
uniform mat4 projection = mat4(1.0f);

out vec4 vertexColor;
out vec2 TexCoord;
void main()
{
    gl_Position = projection * view * transform * vec4(aPos, 1.0);
    TexCoord = vec2(tex.x, tex.y);
    vertexColor = vec4(aColor.x, aColor.y, aColor.z, 1.0); // set the output variable to a dark-red color
})";
#pragma endregion

	unsigned int VAO;	//Vertex Array object, stores vertex attributes
	unsigned int VBO;	//Vertex buffer object, stores vertices data
	unsigned int EBO;	//Element Buffer Objects, stores indices to specify to OpenGL what vertices t draw

	unsigned int vertexShader;
	unsigned int fragmentShader;

	unsigned int shaderProgram;

	glm::mat4x4 view;
	glm::mat4x4 projection;

public:
	Renderer();
	~Renderer();

	void Init();
	void ShaderStart();
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

	void DrawSprite(glm::mat4x4& entityModel, unsigned int& texture);

	void CompileErrorCheck(unsigned int& shader);
};