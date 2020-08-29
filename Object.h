#pragma once
#include <glm/glm.hpp>
namespace Graphics
{
	class Object
	{
	public:
		void setOrientation(glm::mat3 orientation3d)
		{
			orientation = orientation3d;
		}

		void setPosition(glm::vec3 position3d)
		{
			position = position3d;
		}

		glm::vec3 getPosition() const
		{
			return position;
		}

		glm::mat3  getOrientation() const
		{
			return orientation;
		}

		glm::mat4 getTransformMatrix() const
		{
			return glm::mat4
			(
				orientation[0][0], orientation[0][1], orientation[0][2], 0.0,
				orientation[1][0], orientation[1][1], orientation[1][2], 0.0,
				orientation[2][0], orientation[2][1], orientation[2][2], 0.0,
				position.x, position.y, position.z, 1.0f
			);
		}

		void setTransformMatrix(glm::mat4 matrix)
		{
			orientation = glm::mat3
			(
				matrix[0][0], matrix[0][1], matrix[0][2],
				matrix[1][0], matrix[1][1], matrix[1][2],
				matrix[2][0], matrix[2][1], matrix[2][2]
			);
			position = glm::vec3(matrix[3][0], matrix[3][1], matrix[3][2]);
		}

	private:
		glm::mat3 orientation=glm::mat3(1.0f);
		glm::vec3 position=glm::vec3(0.0f,0.0f,0.0f);
	};
}
