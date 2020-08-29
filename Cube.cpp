#include "Cube.h"
using namespace Graphics;

void Cube::init(std::string const& path)
{
	model = new Model();
	model->init(path);
}

void Cube::render(ShaderProgram& program, Camera& camera)
{
	//glEnable(GL_CULL_FACE);
	program.use();
	program.setMat4("viewProjection", camera.getViewProjection());
	program.setMat4("model", getTransformMatrix());

	//program.setVec3("lightPos", camera.getPosition());
	//program.setVec3("viewPos", camera.getPosition());
	//program.setVec3("objectColor", glm::vec3(1.0f, 0.5f, 0.31f));
	//program.setVec3("lightColor", glm::vec3(1.0f, 1.0f, 1.0f));

	model->Draw(program);
//	glDisable(GL_CULL_FACE);
}


void Cube::clean()
{
}
