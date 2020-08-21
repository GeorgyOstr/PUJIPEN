#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

#include <glew.h>

namespace Graphics
{
	class Shader
	{
	public:
		void init(int type);

		void read(std::string file_path);

		void compile();

		GLuint getId();

		void clean();

	private:
		GLuint shaderId;

		int shaderType;

		std::string shaderCode;

	};
}