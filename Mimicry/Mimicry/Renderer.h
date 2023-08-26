#pragma once
class Renderer
{
private:

    float vertices[9] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
    };

public:
	Renderer();
	~Renderer();

	void RenderFrame();
};