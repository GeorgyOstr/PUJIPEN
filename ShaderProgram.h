#pragma once
#include "Shader.h"

// Include GLM
#include <glm.hpp>
#include <gtx/transform.hpp> 
#include <gtc/matrix_transform.hpp>

namespace Graphics
{
	class ShaderProgram
	{
	public:
		ShaderProgram() = default;

		ShaderProgram(const char* vertex_file_path, const char* fragment_file_path);

		void use();

		void setMat4(const std::string& name, const glm::mat4& mat) const;

		void setVec3(const std::string& name, const glm::vec3& value) const;

		void setInt(const std::string& name, int value) const;

		void clean();

	private:
		Shader vertex;

		Shader fragment;

		GLuint ID;

	};
}

