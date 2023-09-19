#pragma once

class __declspec(dllexport) Renderer
{
public:
	Renderer();
	~Renderer();

	void LoadVertexData(unsigned int& VAO, unsigned int& VBO, float* vertices, int verticesSize);
	void LoadIndexData(unsigned int& EBO, unsigned int* indices, int indicesSize);
	void LoadVertexAttributes(unsigned int& VAO, unsigned int& VBO, float* vertices);

	void CreateShaderProgram(unsigned int& shaderProgram);
	void InitVertexShader(const char* shaderSource, unsigned int& vertexShader, int vertexAttributeSize, unsigned int& shaderProgram);
    void InitFragmentShader(const char* shaderSource, unsigned int& fragmentShader, unsigned int& shaderProgram);

	void GenBufferObjects(unsigned int& buffer, int bufferID);
	void GenVAO(unsigned int& buffer, int bufferID);

    void ClearFrame();

	void DrawEntity2D(unsigned int& shaderProgram, unsigned int& VAO);

    void CompileErrorCheck(unsigned int& shader);
};