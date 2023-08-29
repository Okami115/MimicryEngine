#pragma once
class Renderer
{
private:

public:
	Renderer();
	~Renderer();

    void InitRenderer();
    void InitVertexShader();
    void InitFragmentShader();

    void ClearFrame();
	void RenderFrame();

    void CompileErrorCheck(unsigned int shader);
};