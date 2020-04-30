#include <iostream>
#include <Windows.h>
#include <gl/glew.h>
#include <gl/glfw3.h>
#include "Renderer.h"
#include<gl\glut.h>

bool InitGraphics();
int KeyPressed = -1;
double MouseXPos = -1.0;
double MouseYPos = -1.0;
void SpecialKeyPressed(GLFWwindow*, int, int, int, int);
void MouseClicked(GLFWwindow*, int, int, int);

bool mouseclicked = false;

int main(int argc, char **argv)
{

	
	InitGraphics();
	return 0;
}
void SpecialKeyPressed(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS || action == GLFW_REPEAT)
		KeyPressed = key;

}
void MouseClicked(GLFWwindow* window, int button, int action, int mods)
{
	if (action == GLFW_MOUSE_BUTTON_LEFT)
		mouseclicked = true;
}
/** 
Creates the main window and initializes OpenGL stuff.
*/
bool InitGraphics()
{
	Renderer *renderer = new Renderer(); //All drawing code goes here
	GLFWwindow* window;

	// ******************** Initialise GLFW ******************** //
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		return false;
	}

/*	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //OpenGL version 3.
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // 3.3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //If requesting an OpenGL version below 3.2, GLFW_OPENGL_ANY_PROFILE
	*/
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow( 1024, 768, "Pacman", NULL, NULL);
	if( window == NULL ){
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(window);

	// ******************** Initialize GLEW ******************** //
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return false;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE); 
	glfwSetKeyCallback(window, &SpecialKeyPressed);

	// ******************** Initialize OpenGL ******************** //
	renderer->Initialize();

	do{ // Loop

		renderer->Draw();
		renderer->Update();

		if (KeyPressed != -1)
		{
			renderer->HandleKeyboardInput(KeyPressed);
			KeyPressed = -1;
		}		// Swap buffers
		if (mouseclicked != false)
		{
			glfwGetCursorPos(window, &MouseXPos, &MouseYPos);
			renderer->HandleMouseClick(MouseXPos, MouseYPos);
			mouseclicked = false;
		}
		glfwSwapBuffers(window); //Displaying our finished scene
		glfwPollEvents(); //try to comment it

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0 );

	// Close OpenGL window and terminate GLFW
	glfwTerminate();
    // Deleting renderer object will deallocate it's memory and call it's destructor (which calls the renderer's Cleanup method)
    delete renderer;
    return true;

}
