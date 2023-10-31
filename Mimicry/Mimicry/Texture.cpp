#include "Texture.h"
#include "../Mimicry/TextureImporter.h"

Texture::Texture(std::string path)
{
	this->path = path;
}

Texture::~Texture()
{

}

bool Texture::LoadTexture(std::string path)
{
	this->path = path;
	return TextureImporter::LoadTexture(this->path, texture2D, width, height, channels);
}