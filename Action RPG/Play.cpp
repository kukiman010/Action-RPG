#include "Play.h"



Play::Play()
{
	setup();
	RenderWindow window(sf::VideoMode(width, height), "Action-RPG");
	Player pl("player.png",60,60);

	float c_x, c_y;
	c_x = pl.pl_x();
	c_y = pl.pl_y();

	while (window.isOpen())
	{
		time_window = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time_window = time_window / 500;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			pl.direction = "LEFT";
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			pl.direction = "RIGHT";
		}
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			pl.direction = "UP";
			//snake_1.sprite.move(0, -0.1*time_window);
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			pl.direction = "DOWN";
			//snake_1.sprite.move(0, 0.1*time_window);
		}
		if (Keyboard::isKeyPressed(Keyboard::P))
		{
			pl.direction = "STOP";
		}
		if (Keyboard::isKeyPressed(Keyboard::T))
		{
			pl.direction = "TELEPORT";
		}



		pl.motion(pl.direction, time_window);
		//cout << pl.direction << " " << pl.pl_x() << " " << pl.pl_y() << "\n";


		window.clear();
		window.draw(pl.sprite);
		window.display();
	}
}

void Play::setup()
{
	width = 400;
	height = 300;
}


Play::~Play()
{
}
