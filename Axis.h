#pragma once
#include "Drawable.h"

namespace Graphics {
	class Axis : public Drawable
	{
	public:
		void init();

		void render(ShaderProgram& program, Camera& camera);

		void clean()
		{

		}

	private:
		GLfloat lineWidth = 10.0f;
		GLuint VAO;

		GLuint VBO;
		GLuint EBO;
	};
}

