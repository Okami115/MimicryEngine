#pragma once
#include "Engine/Shape.h"

class Renderer
{
private:


	unsigned int shaderProgram;


	unsigned int VAO;
	unsigned int EBO;




public:
	Renderer();
	~Renderer();

    void InitRenderer();
	void InitShape(Shape& shape);
    void InitVertexShader(Shape& shape);
    void InitFragmentShader(Shape& shape);

    void ClearFrame();
	void RenderFrame();

	void RenderShape(Shape shape);

    void CompileErrorCheck(unsigned int shader);
};