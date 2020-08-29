#include "Renderer.h"
#include <filesystem>
using namespace Graphics;

void Renderer::init(GLfloat width, GLfloat height)
{
	Width = width;
	Height = height;
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return;
	}
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(Width, Height, "PUJIPEN", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		glfwTerminate();
	}
	glfwMakeContextCurrent(window); // Initialize GLEW
	glewExperimental = true; // Needed in core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
	}
	glViewport(0, 0, Width, Height);
	camera.init();
	control = new Controls(window, &camera);

	modelProgram = ShaderProgram("ModelTextured.vs", "ModelTextured.fs");
	
	std::string path = std::filesystem::current_path().string();
	std::replace(path.begin(), path.end(), '\\', '/');
	
	const auto cube = new Cube();
	cube->init(path + "/resources/axis.fbx");
	
	const auto cube2 = new Cube();
	cube2->init(path + "/resources/axis.fbx");
	cube2->setPosition(glm::vec3(10.0f, 10.0f, 10.0f));
	cube2->setOrientation(glm::mat3(
		1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
		0.0f, -1.0f, 0.0f));

	objects.emplace_back(cube);
	objects.emplace_back(cube2);

	//Keyboard, mouse, window basic set up
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	glfwPollEvents();
	glfwSetCursorPos(window, Width / 2, Height / 2);
	glClearColor(0.4f, 0.5f, 0.3f, 0.0f);
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Renderer::render()
{
	// Clear the screen
	// glClear(GL_COLOR_BUFFER_BIT);
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (auto& object : objects) // access by reference to avoid copying
	{
		object->render(modelProgram, camera);
	}

	glfwSwapBuffers(window);
	glfwPollEvents();
}



int Renderer::isWorking()
{
	return glfwWindowShouldClose(window);
}

void Renderer::cleanUp()
{
	for (auto& object : objects) // access by reference to avoid copying
	{
		object->clean();
	}

	glfwTerminate();
}