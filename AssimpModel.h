#pragma once
#include "Mesh.h"
#include "Model.h"
#include "Drawable.h"

namespace Graphics
{
	class AssimpModel : public Drawable
	{
	public:
		void init();

		void render(ShaderProgram& program, Camera& camera);

		void clean();

		void setPath(std::string const& path_in)
		{
			path = path_in;
		}

	private:
		Model* model;
		GLuint polygonMode;
		std::string path;
	};
}
