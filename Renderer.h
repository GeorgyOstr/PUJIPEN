#pragma once
// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <vector>
//OpenGL 
// Include GLEW
#include "../Camera.h"
#include <GL/glew.h>
// Include GLFW
#include <GLFW/glfw3.h>
// Include GLM
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp> 
#include <glm/gtc/matrix_transform.hpp>

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

		Cube* cube;

		ShaderProgram modelProgram;

		GLfloat Width;
		GLfloat Height;
	};
}
