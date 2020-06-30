#include <GL/glew.h>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/GLU.h>
#include <EGL/egl.h>
#include <iostream>

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
	float positions[18] = {
		-0.5f,0.5f,0.0f,
		 0.0f,0.5f,1.0f,
		 0.5f,0.0f,0.5f,
		-0.8f,0.8f,-0.5f,
		 0.0f,0.5f,-1.0f,
		 0.5f,0.0f,0.0f,
	};
	glewInit();
	unsigned int buffer;
	unsigned int bufA ;
	glGenBuffers(1, &bufA);
	glBindBuffer(GL_ARRAY_BUFFER, bufA);
	glBufferData(GL_ARRAY_BUFFER, 12 * sizeof(float), positions, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);

	//ANTIALIASED_QUALITY;

	sf::Clock Clock;

	//Decl_Objs
	while (win->isOpen())
	{
		float nTime = Clock.getElapsedTime().asSeconds();
		win->clear();
		//Draw Game Objects Here...
		glDrawArrays(GL_TRIANGLES, 0, 3);
		//Draw_Objs

		//Event Loop ...
		sf::Event evnts;
		while (win->pollEvent(evnts))
		{
			if (evnts.type == sf::Event::Closed) win->close();
			if (evnts.type == sf::Event::Resized)std::cout<<"resized";
			
		}//Event_loop
		glRotatef(nTime * .3f, 1, 1, 0);
		glRotatef(nTime * .8f, 0, 1, 1);
		glRotatef(nTime * .2f, 1, 0, 1);

		win->display();
		if (nTime >= 1.9f ) Clock.restart();
	}
}
