#include "squareOBjects.h"

squareObj::squareObj()
{
	glClearDepth(1.f);
	glClearColor(0.3f, 0.3f, 0.3f, 0.f);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	//// Setup a perspective projection & Camera position
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(112.f, 1.f, 1.f, 300.0f);//fov, aspect, zNear, zFar
}

squareObj::~squareObj()
{
}

int squareObj::drawObject(int number_of_faces, sf::Vector3f object_Loc)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.f, 0.f, -200.f);
	glBegin(GL_QUADS);
	glRotatef(60, 1, 1, 1);
	for (int i = 0; i < number_of_faces; i++) {
		object_Loc.x *= -1;
		object_Loc.y *= -1;
		object_Loc.z *= -1;
		mesh_initialiser(object_Loc);
	}
	glEnd();
	return 0;
}

void squareObj::mesh_initialiser(sf::Vector3f mesh_Loc)
{
	glColor3f(1, 0, 0);
	glVertex3f(-mesh_Loc.x, -mesh_Loc.y, -mesh_Loc.z);
	glVertex3f(-mesh_Loc.x, mesh_Loc.y, -mesh_Loc.z);
	glVertex3f(mesh_Loc.x, mesh_Loc.y, -mesh_Loc.z);
	glVertex3f(mesh_Loc.x, -mesh_Loc.y, -mesh_Loc.z);
}
