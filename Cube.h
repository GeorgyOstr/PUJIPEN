#pragma once


#include "Mesh.h"
#include "Model.h"
#include "Camera.h"

namespace Graphics
{
	class Cube
	{
	public:
		void Cube::init(std::string const& path);

		void update(ShaderProgram& program);

		void clean();

	private:
		Model* model;
		GLuint polygonMode;
	};
}
