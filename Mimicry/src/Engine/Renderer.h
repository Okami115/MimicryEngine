#pragma once

class Renderer
{
private:
#pragma region FRAGMENT SHADER
	const char* fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\0";
	unsigned int fragmentShader;
#pragma endregion

#pragma region VERTEX SHADER
	const char* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";
	unsigned int vertexShader;
#pragma endregion

	unsigned int VAO;
	unsigned int EBO;

	float vertex[12] = {
	0.5f, 0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 -0.5f,  -0.5f, 0.0f,
	 -0.5f, 0.5f, 0.0f
	};

	unsigned int indices[6] = {
		0,1,3,
		1,2,3
	};



public:
	Renderer();
	~Renderer();

	void LoadVertexData(unsigned int& VBO, float* vertices);
	//void InitShape(Shape& shape);
    void InitVertexShader(const char* shaderSource, unsigned int& vertexShader, int vertexAttributeSize, unsigned int shaderProgram);
    void InitFragmentShader(const char* shaderSource, unsigned int& fragmentShader, unsigned int shaderProgram);

	void GenBuffer(unsigned int buffer, int bufferID);

    void ClearFrame();

	void DrawShape(unsigned int& shaderProgram, unsigned int& VAO);

    void CompileErrorCheck(unsigned int shader);
};