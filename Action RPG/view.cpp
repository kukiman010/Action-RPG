#include "view.h"



view::view(int wind_x, int wind_y)
{
	vi.reset(FloatRect(0, 0, wind_x, wind_y));
}


View view::GetPlayerView(int x, int y, int window_x, int window_y)
{
	int temp_x = x, temp_y = y;

	if (x < window_x / 2) temp_x = window_x / 2;
	if (x > 3231 - (window_x / 2)) temp_x = 3231 - (window_x / 2);
	if (y < window_y / 2) temp_y = window_y / 2;
	if (y > 4468 - (window_y / 2)) temp_y = 4468 - (window_y / 2);

	vi.setCenter(temp_x, temp_y);
	return vi;
}

view::~view()
{
}
