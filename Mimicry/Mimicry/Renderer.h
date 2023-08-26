#pragma once
class Renderer
{
private:
    unsigned int VBO;

    float vertices[9] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
    };

public:
	Renderer();
	~Renderer();

    void InitRenderer();

    void ClearFrame();
	void RenderFrame();
};