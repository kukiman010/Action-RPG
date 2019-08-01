#include "Play.h"



Play::Play()
{
	RenderWindow window(VideoMode(800, 600), "Action RPG");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	while (window.isOpen()) 
	{
		Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear(Color::Black);
		// draw everything here...
		// window.draw(...);
		window.display();
	}
}


Play::~Play()
{
}
