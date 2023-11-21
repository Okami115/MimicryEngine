#include "Utility.h"
#include <fstream>
#include <sstream>
#include <iostream>


std::string Utility::ReadShader(std::string Path)
{
	std::string src;
	std::ifstream fShaderFile;

	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try 
	{
		fShaderFile.open(Path);
		std::stringstream vShaderStream, fShaderStream;
		fShaderStream << fShaderFile.rdbuf();
		fShaderFile.close();
		src = fShaderStream.str();
	}
	catch (std::ifstream::failure& e) 
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}
	return src;

}

void Utility::ShaderStart()
{
	ReadShader(GetTextureVertexShaderPath());
	ReadShader(GetTextureFragmentShaderPath());
}

std::string Utility::GetTextureVertexShaderPath()
{
	return "../src/Source/Shader/TextureVertexShader.shader";
}

std::string Utility::GetTextureFragmentShaderPath()
{

	return "../src/Source/Shader/TextureFragmentShader.shader";
}

UV::UV(float U, float V)
{
	this->U = U;
	this->V = V;
}

UV::UV()
{
	U = 0;
	V = 0;
}

vec3::vec3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

vec3::vec3()
{
	x = 0;
	y = 0;
	z = 0;
}

