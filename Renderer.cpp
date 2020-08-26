#include "Renderer.h"
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
	window = glfwCreateWindow(Width, Height, "Robot Simulator", NULL, NULL);
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
	
	cube = new Cube();
	cube->init("D:/ane/0.obj");

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
	cube->render(modelProgram, camera);

	glfwSwapBuffers(window);
	glfwPollEvents();
}



int Renderer::isWorking()
{
	return glfwWindowShouldClose(window);
}

void Renderer::cleanUp()
{
	cube->clean();

	glfwTerminate();
}