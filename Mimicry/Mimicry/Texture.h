#pragma once
#include <iostream>
#include "../src/Engine/Exports.h"
class MimicryEngine_API Texture
{
private:
	std::string path;
	int channels;
public:
	int width;
	int height;
	unsigned int texture2D;
	Texture(std::string path);
	Texture();
	~Texture();

	bool LoadTexture(std::string path);
};

