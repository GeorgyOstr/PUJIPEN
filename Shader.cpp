#include "Shader.h"
using namespace Graphics;

void Shader::init(int type)
{
	shaderType = type;
	shaderId = glCreateShader(type);
}

void Shader::read(std::string file_path)
{
	std::ifstream shaderStream(file_path, std::ios::in);
	if (shaderStream.is_open()) {
		std::stringstream sstr;
		sstr << shaderStream.rdbuf();
		shaderCode = sstr.str();
		shaderStream.close();
	}
	else {
		throw std::runtime_error
		(
			"Could not load the shader " + file_path
		);
	}
}

void Shader::compile()
{
	//Compile
	char const* sourcePointer = shaderCode.c_str();
	glShaderSource(shaderId, 1, &sourcePointer, NULL);
	glCompileShader(shaderId);

	// Check Shader
	GLint Result = GL_FALSE;
	int InfoLogLength;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &InfoLogLength);
	//TODO change to throw error; not printf
	if (InfoLogLength > 0) {
		std::vector<char> shaderErrorMessage(InfoLogLength + 1);
		glGetShaderInfoLog(shaderId, InfoLogLength, NULL, &shaderErrorMessage[0]);
		printf("%s\n", &shaderErrorMessage[0]);
	}
}

GLuint Shader::getId()
{
	return shaderId;
}

void Shader::clean()
{
	glDeleteShader(shaderId);
}
