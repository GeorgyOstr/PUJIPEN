#include "ShaderProgram.h"
using namespace Graphics;

ShaderProgram::ShaderProgram(const char* vertex_file_path, const char* fragment_file_path) {
	vertex.init(GL_VERTEX_SHADER);
	vertex.read(vertex_file_path);
	vertex.compile();

	fragment.init(GL_FRAGMENT_SHADER);
	fragment.read(fragment_file_path);
	fragment.compile();
	// Link the program
	printf("Linking program\n");
	ID = glCreateProgram();
	glAttachShader(ID, vertex.getId());
	glAttachShader(ID, fragment.getId());
	glLinkProgram(ID);

	// Check the program
	GLint Result = GL_FALSE;
	int InfoLogLength;
	glGetProgramiv(ID, GL_LINK_STATUS, &Result);
	glGetProgramiv(ID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if (InfoLogLength > 0) {
		std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
		glGetProgramInfoLog(ID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
		printf("%s\n", &ProgramErrorMessage[0]);
	}

	glDetachShader(ID, vertex.getId());
	glDetachShader(ID, fragment.getId());

	vertex.clean();
	fragment.clean();
}

void ShaderProgram::use()
{
	glUseProgram(ID);
}

void ShaderProgram::setMat4(const std::string& name, const glm::mat4& mat) const
{
	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void ShaderProgram::setVec3(const std::string& name, const glm::vec3& value) const
{
	glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}

void ShaderProgram::setInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void ShaderProgram::clean()
{
	glDeleteProgram(ID);
}



