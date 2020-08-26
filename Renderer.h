#pragma once
// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Camera.h"
#include "Controls.h"

#include "Cube.h"

namespace Graphics {
	class Renderer
	{
	public:
		void init(GLfloat width, GLfloat height);

		void render();

		void cleanUp();

		int isWorking();

	private:
		GLFWwindow* window;
		Camera camera;
		Controls* control;

		Cube* cube;

		ShaderProgram modelProgram;

		GLfloat Width;
		GLfloat Height;
	};
}
