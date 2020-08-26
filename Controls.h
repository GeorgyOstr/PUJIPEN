#pragma once
#include "../Camera.h"
// Include GLFW
#include <GLFW/glfw3.h>
// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <cmath>


using namespace glm;

namespace Graphics
{
	class Controls
	{
	public:
		Controls(GLFWwindow* in_window, Camera* in_camera)
		{
			glfwSetErrorCallback(error_callback);
			window = in_window;
			camera = in_camera;
			glfwSetWindowUserPointer(window, this);
			glfwSetScrollCallback(window, scroll_callback);
			glfwSetKeyCallback(window, key_callback);
			glfwSetCursorPosCallback(window, cursor_position_callback);
			glfwSetMouseButtonCallback(window, cursor_key_callback);
			
		}

	private:
		GLFWwindow* window;

		Camera* camera;

		glm::vec3 clicked;

		glm::mat4 cameraBeforeMove;
		
		static void error_callback(int error, const char* description);

		static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

		static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

		static void cursor_key_callback(GLFWwindow* window, int button, int action, int mods);
	};
}
