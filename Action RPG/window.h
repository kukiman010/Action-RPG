#pragma once
#include "Libres.h"

class WINDOW
{
private:
	void winEvents();
	bool focused = true;
	RenderWindow window;
public:

	WINDOW();
	RenderWindow& get();
	void clear();
	void update();
	bool isOpen();
	bool isFocus();
	void close();
	void setView(const View& view);
	void draw(const Drawable& drawable, const RenderStates& states = RenderStates::Default);
};

