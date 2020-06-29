#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/GLU.h>
#include <iostream>
#include "squareObjects.h"

static const sf::Vector2i WIN_SIZE{ 600,600 };
void gameLoop(sf::RenderWindow* win);

/*--------------------------------------------------------------------------------
  ---            SFML project by Zadock Maloba                                 ---
  ---                                                                          ---
  ---   E-mail: malobazadock@gmail.com || Tweeter: @Zadock_254                 ---
  --------------------------------------------------------------------------------
*/


int main()
{
	sf::RenderWindow win(sf::VideoMode(WIN_SIZE.x,WIN_SIZE.y, 32), "SFML/OpenGL", sf::Style::Close | sf::Style::Resize);
	gameLoop(&win);
}

void gameLoop(sf::RenderWindow* win)
{
	//Declare objects not meant to be in the Loop here...
	/*glClearDepth(1.f);
	glClearColor(0.3f, 0.3f, 0.3f, 0.f);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	//// Setup a perspective projection & Camera position
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(112.f, 1.f, 1.f, 300.0f);//fov, aspect, zNear, zFar */

	sf::Clock Clock;
	bool rotate = true;
	float angle;
	squareObj sqrbj;

	//Decl_Objs
	while (win->isOpen())
	{
		win->clear();
		//Draw Game Objects Here...


		//Draw_Objs

		//Event Loop ...
		sf::Event evnts;
		while (win->pollEvent(evnts))
		{
			if (evnts.type == sf::Event::Closed) win->close();
			if (evnts.type == sf::Event::Resized)std::cout<<"resized";
			if ((evnts.type == sf::Event::KeyPressed) && (evnts.key.code == sf::Keyboard::A)) {
				rotate = !rotate;
			}
		}//Event_loop
		 // Apply some transformations for the cube
		/*glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(0.f, 0.f, -200.f);*/

		if (rotate) {
			angle = Clock.getElapsedTime().asSeconds();
		}
		glRotatef(angle * 50, 1.f, 0.f, 0.f);
		//glRotatef(angle * 30, 0.f, 1.f, 0.f);
		glRotatef(angle * 90, 0.f, 0.f, 1.f);

		//Draw a cube
		sqrbj.drawObject(4,sf::Vector3f(50,20,60));
		/*
		glBegin(GL_QUADS);//draw some squares
		glColor3i(0, 1, 1);
		glVertex3f(-50.f, -50.f, -50.f);
		glVertex3f(-50.f, 50.f, -50.f);
		glVertex3f(50.f, 50.f, -50.f);
		glVertex3f(50.f, -50.f, -50.f);

		glColor3f(0, 0, 1);
		glVertex3f(-50.f, -50.f, 50.f);
		glVertex3f(-50.f, 50.f, 50.f);
		glVertex3f(50.f, 50.f, 50.f);
		glVertex3f(50.f, -50.f, 50.f);

		glColor3f(1, 0, 1);
		glVertex3f(-50.f, -50.f, -50.f);
		glVertex3f(-50.f, 50.f, -50.f);
		glVertex3f(-50.f, 50.f, 50.f);
		glVertex3f(-50.f, -50.f, 50.f);

		glColor3f(0, 1, 0);
		glVertex3f(50.f, -50.f, -50.f);
		glVertex3f(50.f, 50.f, -50.f);
		glVertex3f(50.f, 50.f, 50.f);
		glVertex3f(50.f, -50.f, 50.f);

		glColor3f(1, 0, 0);
		glVertex3f(-50.f, -50.f, 50.f);
		glVertex3f(-50.f, -50.f, -50.f);
		glVertex3f(50.f, -50.f, -50.f);
		glVertex3f(50.f, -50.f, 50.f);

		glColor3f(1, 0, 0);
		glVertex3f(-50.f, 50.f, 50.f);
		glVertex3f(-50.f, 50.f, -50.f);
		glVertex3f(50.f, 50.f, -50.f);
		glVertex3f(50.f, 50.f, 50.f);

		glEnd();
		*/
		win->display();
	}
}
