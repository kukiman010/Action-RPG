#pragma once
#include "Libres.h"

class view
{
//private:
	//View vi;
public:
	View vi;
	view(int wind_x, int wind_y);
	View GetPlayerView(int x, int y, int window_x, int window_y);
	~view();
};

