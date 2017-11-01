#include <windows.h>
#include <iostream>
//glew
#include <GL/glew.h>
#include <GL/GL.h>

//glfw
#include <GLFW/glfw3.h>
#include "Game.h"

const int screenWidth = 800;
const int screenHeight = 600;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouse_callback(GLFWwindow* window, double posx, double posy);
void mouse_button_callback(GLFWwindow* window, int b, int action, int);

Game BreakOut(screenWidth, screenHeight);;

int main()
{

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_SAMPLES, 4); //msaa

	GLFWwindow* window = glfwCreateWindow(screenWidth, screenHeight, "LearnOpenGL", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);


	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}
	glGetError();
	glEnable(GL_MULTISAMPLE);//msaa
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	BreakOut.Init();

	while (!glfwWindowShouldClose(window))
	{

		BreakOut.Render();
	}

	glfwTerminate();

	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
	if (key == GLFW_KEY_P && action == GLFW_PRESS)
	{
/*		play = true;*/
	}
	if (action == GLFW_PRESS)
	{
		//keys[key] = true;
	}
	else if (action == GLFW_RELEASE)
	{
// 		keys[key] = false;
// 		keysPressed[key] = false;
	}

}
void mouse_callback(GLFWwindow* window, double posx, double posy)
{
// 	if (firstMouse)
// 	{
// 		lastX = posx;
// 		lastY = posy;
// 		firstMouse = false;
// 	}
// 
// 	GLfloat offsetx = posx - lastX;
// 	GLfloat offsety = lastY - posy;
// 	lastX = posx;
// 	lastY = posy;
// 
// 	camera.ProcessMouseMovement(offsetx, offsety);

}
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	// 	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	// 	{
	// 		std::cout << "clicked" << std::endl;
	// 		screenCoordsTo3DCoords(lastX, lastY);
	// 	}
}