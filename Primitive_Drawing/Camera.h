#pragma once
#include <gl/glew.h>
#include<gl/glfw3.h>
#include "shader.hpp"
#include <glm/glm.hpp> 
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform.hpp>
#include<glm\gtx\rotate_vector.hpp>
using namespace glm;
class Camera
{
	vec3 Position;
	vec3 Back, Up, Right;


public:
	Camera();
	float x, z;
	float px, py, pz;
	void setpx(float x);
	void setpz(float z);
	float getx();
	float getz();
	Camera(vec3 _Position, vec3 _LoolAtPoint, vec3 UpDirection);
	void strafe(float steps);
	mat4 GetViewMatrix();
	void yaw(float angle);
	void walk(float steps);
	void fly(float angel);
	void roll(float angle);
	void pitch(float angle);
	~Camera();
};

