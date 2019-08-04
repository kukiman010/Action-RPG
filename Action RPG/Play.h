#pragma once

#include "Libres.h"
#include "Player.h"
#include "locations.h"
#include "view.h"
#include "fps_counter.h"
#include "window.h"

class Play
{
private:
	Clock clock;
	float time_window;
	/*int width;
	int height;*/

	WINDOW window;

public:
	Play();
	void setup();
};

