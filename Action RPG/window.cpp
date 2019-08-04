#include "window.h"



WINDOW::WINDOW()
{
	window.create(VideoMode(win_info::width, win_info::height), "Action-RPG");
	window.setFramerateLimit(60);
}

RenderWindow& WINDOW::get()
{
	return window;
}

void WINDOW::clear()
{
	window.clear();
}

void WINDOW::update()
{
	window.display();
	winEvents();
}

bool WINDOW::isOpen()
{
	return window.isOpen();
}

bool WINDOW::isFocus() {
	return focused;
}

void WINDOW::winEvents()
{
	sf::Event e;

	while (window.pollEvent(e))
	{
		if (e.type == Event::Closed)
		{
			window.close();
		}
		else if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		else if (e.type == Event::GainedFocus) {
			focused = true;
		}
		else if (e.type == Event::LostFocus) {
			focused = false;
		}
	}
}

void WINDOW::close()
{
	window.close();
}

void WINDOW::setView(const View & view)
{
	window.setView(view);
}

void WINDOW::draw(const Drawable & drawable, const RenderStates & states)
{
	window.draw(drawable, states);
}
