#include "TextureImporter.h"
#include "glfw3.h"
#include "../Mimicry/stb_image.h"
#include <iostream>

bool TextureImporter::LoadTexture(const std::string& path, unsigned int& texture, int& width, int& height, int& channels)
{
	unsigned char* data = nullptr;
	stbi_set_flip_vertically_on_load(false);

	std::string pathData = path;

	if (!data)
	{
		std::cout << "TEXTURE::ERROR::001" << std::endl;
		return false;
	}

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, 0);

	stbi_image_free(data);
	return true;
	
}