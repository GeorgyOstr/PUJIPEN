#include "controls.h"
#define _USE_MATH_DEFINES
using namespace Graphics;

void Controls::error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

void Controls::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

}

void Controls::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	void* voidControl = glfwGetWindowUserPointer(window);
	Controls* control = static_cast<Controls*>(voidControl);
	if (yoffset>0)
	{
		control->camera->setZoom(1.1);
	}
	else
	{
		control->camera->setZoom(0.9);
	}
}

glm::vec3 rotateRodrigues(glm::vec3 vector, glm::vec3 rotationAxis, GLfloat deg)
{
	return vector * std::cos(deg) +
		glm::cross(rotationAxis, vector) * std::sin(deg) +
		rotationAxis * glm::dot(rotationAxis, vector) * (1 - std::cos(deg));
}

void Controls::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	void* voidControl = glfwGetWindowUserPointer(window);
	Controls* control = static_cast<Controls*>(voidControl);

	const float x = (xpos - control->clicked[0])/1920.0*3.14;
	const float y = (ypos - control->clicked[1])/1080.0*3.14;
	
	const glm::mat4 camB = control->cameraBeforeMove;
	glm::vec3 oldFront = glm::vec3(-camB[0][2], -camB[1][2], -camB[2][2]);
	glm::vec3 oldRight = glm::vec3(camB[0][0], camB[1][0], camB[2][0]);
	glm::vec3 oldUp = glm::cross(oldFront, oldRight);
	
	glm::vec3 newFront = glm::normalize(oldFront + oldRight * x + oldUp*y);
	const mat4 transform = glm::lookAt(
		control->camera->getPosition() - newFront,
		control->camera->getPosition(),
		-oldUp);
	
	if (control->clicked[2] == 1.0)
	{
		control->camera->setOrientation(transform);
	}
}



void Controls::cursor_key_callback(GLFWwindow* window, int button, int action, int mods)
{
	void* voidControl = glfwGetWindowUserPointer(window);
	Controls* control = static_cast<Controls*>(voidControl);

	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		control->clicked = glm::vec3(xpos, ypos, 1.0);
		control->cameraBeforeMove = control->camera->getTransformMatrix();
	}
	else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
		control->clicked = glm::vec3(xpos, ypos, 0.0);
	}
}