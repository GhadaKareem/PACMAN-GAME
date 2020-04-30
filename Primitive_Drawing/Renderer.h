#include <gl/glew.h>
#include<gl/glfw3.h>
#include "shader.hpp"
#include <glm/glm.hpp> 
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform.hpp>
#include"texture.h"
#include"Camera.h"
using namespace glm;


#pragma once

class Renderer
{
	GLuint vertexArrayID;
	GLuint vertexBufferID;
	GLuint programID;

	GLuint MatrixID;
	

	mat4 ModelMatrix;
	mat4 ProjectionMatrix;
	mat4 ViewMatrix;

	mat4 ModelMatrix1;
	mat4 ModelMatrix2;
	mat4 MVP_M1;
	mat4 MVP_M3;
	mat4 MVP_M2;
	mat4 MVP_M4;
	
	mat4 maze1;
	mat4 player;
	mat4 enemy1;
	mat4 enemy2;
	mat4 food1;
	mat4 food2;
	mat4 food3;
	mat4 food4;
	mat4 food5;

	mat4 enemyRot;
	Camera Maincamera;
	Texture *t_UP, *t_DOWN, *t_FRONT, *t_BACK, *t_RIGHT, *t_LEFT, *Enemy,*Hero,*Food;
	Texture *mazetxt;
	Texture *groundtxt;
	double time;
	GLuint AmientColorID;
	vec3 AmbientColor;
	GLuint DiffuseLightID;
	vec3 DiffuseLight;
	GLuint LightPoisitionID;
	vec3 LightPoisition;
public:
	Renderer();
	~Renderer();

	void Initialize();
	void Draw();
	void Cleanup();
	void HandleKeyboardInput(int);
	void HandleMouseClick(double, double);
	int Die();
	void Update();
	
	int lifes=3;

};