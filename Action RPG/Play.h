#pragma once

#include "Libres.h"
#include "Player.h"
#include "locations.h"
#include "view.h"

class Play
{
private:
	Clock clock;
	float time_window;
	int width;
	int height;

public:
	Play();
	void setup();
	~Play();
};

