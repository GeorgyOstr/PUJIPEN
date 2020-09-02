#include "Axis.h"
using namespace Graphics;

void  Axis::init()
{
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	GLfloat size = 100.0f;

	std::vector<GLfloat> dataToBuffer = {
	0.0f,	0.0f,	0.0f,	0.0f,	0.0f,	0.0f,
	size,	0.0f,	0.0f,	1.0f,	0.0f,	0.0f,
	0.0f,	size,	0.0f,	0.0f,	1.0f,	0.0f,
	0.0f,	0.0f,	size,	0.0f,	0.0f,	1.0f
	};

	std::vector<unsigned> indices = {
		0, 1,
		0, 2,
		0, 3
	};

	glLineWidth(lineWidth);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(GLfloat), dataToBuffer.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned), indices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Axis::render(ShaderProgram& program, Camera& camera)
{
	program.use();
	program.setMat4("MVP", camera.getViewProjection() * getTransformMatrix());
	glBindVertexArray(VAO);
	glDrawElements(GL_LINES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
