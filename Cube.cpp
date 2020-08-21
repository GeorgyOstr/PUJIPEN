#include "Cube.h"
using namespace Graphics;

void Cube::init(std::string const& path)
{
	model = new Model();
	model->init(path);
}

void Cube::update(ShaderProgram& program)
{
	glEnable(GL_CULL_FACE);
	//glm::mat4 res = camera.getScreenRatioMatrix();
	//glm::mat4 projection = camera.getProjectionMatrix();
	//glm::mat4 view = camera.getViewMatrix();
	//glm::mat4 scale = glm::scale(glm::mat4(), glm::vec3(0.001f, 0.001f, 0.001f)); //Convert model to "m" from "mm"
	//glm::mat4 ratio = camera.getScreenRatioMatrix();
	//glm::vec3 lightPos = camera.getPosition();

	glm::mat4 res = glm::mat4(
		0.5625, 0.0, 0.0, 0.0,
		0.0,1.0,0.0,0.0,
		0.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 0.0, 1.0
	);
	glm::mat4 projection = glm::mat4(
		1.0, 0.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0,
		0.0, 0.0, -0.2, 0.0,
		0.0, 0.0, -1.0, 1.0
	);
	glm::mat4 view = glm::mat4(
		-1.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		0.0, 1.0, 0.0, 0.0,
		0.5, -0.5, -3.0, 1.0
	);
	glm::mat4 scale = glm::mat4(
		0.001, 0.0, 0.0, 0.0,
		0.0, 0.001, 0.0, 0.0,
		0.0, 0.0, 0.001, 0.0,
		0.0, 0.0, 0.0, 1.0
	);
	glm::mat4 ratio = glm::mat4(
		0.5625, 0.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 0.0, 1.0
	);
	glm::vec3 lightPos = glm::vec3(0.5, 2.0, 0.5);
	glm::vec3 viewPos = glm::vec3(0.5, 2.0, 0.5);


	program.use();
	program.setMat4("projection", res * projection);
	program.setMat4("view", view);
	program.setMat4("model", scale);

	program.setVec3("lightPos", lightPos);
	//program.setVec3("viewPos", camera.getPosition());
	program.setVec3("viewPos", viewPos);
	program.setVec3("objectColor", glm::vec3(1.0f, 0.5f, 0.31f));
	program.setVec3("lightColor", glm::vec3(1.0f, 1.0f, 1.0f));
	program.setMat4("projection", ratio * projection);

	model->Draw(program);
	glDisable(GL_CULL_FACE);
}


void Cube::clean()
{
}
