#include "Camera.h"


Camera::Camera()
{

}
Camera::Camera(vec3 _Position, vec3 _LookAtPoint, vec3 UpDirection)
{
	vec3 Dir = _LookAtPoint - _Position;
	Dir = normalize(Dir);
	Right = normalize(cross(Dir, UpDirection));
	Up = normalize(cross(Right, Dir));
	Back = -Dir;

	Position = _Position;

}
void Camera::setpx(float px)
{
	x = px;
}
void Camera::setpz(float pz)
{
	z = pz;
}
float Camera::getx()
{
	return x;
}
float Camera::getz()
{
	return z;
}

mat4 Camera::GetViewMatrix()
{

	vec3 center = vec3(getx(),0, getz());
	return lookAt(Position, center, Up);
}
void Camera::strafe(float steps)
{
	Position += steps *Right;


}

void Camera::yaw(float angle)
{
	Right = rotate(Right, angle, Up);
	Back = rotate(Back, angle, Up);

}
void Camera::walk(float steps)
{
	Position -= steps*Back;
}
void Camera::fly(float steps)
{
	Position -= steps*Up;
}

void Camera::roll(float angle)
{
	Right = rotate(Right, angle, Back);
	Up = rotate(Up, angle, Back);
}

void Camera::pitch(float angle)
{
	Up = rotate(Up, angle, Right);
	Back = rotate(Back, angle, Right);
}
Camera::~Camera()
{
}
