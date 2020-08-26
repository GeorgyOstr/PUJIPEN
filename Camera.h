#pragma once
#include "Object.h"

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp> 
#include <glm/gtc/matrix_transform.hpp>

namespace Graphics
{
	//Ortho for now
	class Camera : public Object
	{
	public:
		void init()
		{
			setPosition(glm::vec3(0.0, 0.0, -20.0));
			setOrientation(glm::lookAt(getPosition(), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)));
		}

		glm::mat4 getViewProjection() const
		{
			const glm::mat4 View = getTransformMatrix();
			glm::mat4 Projection = glm::ortho(-zoom * screenRatio / 2, zoom * screenRatio / 2, -zoom / 2, zoom / 2, near, far);
			return Projection * View;
		}
		
		void setZoom(GLfloat z)
		{
			zoom = zoom*z;
		}
	
	private:
		GLfloat near = 1.0f;
		GLfloat far = 100.0f;

		GLfloat screenRatio = 1920.0f / 1080.0f;
		GLfloat zoom = 50.0f; //Value = distance between Up and Down
	};
}

