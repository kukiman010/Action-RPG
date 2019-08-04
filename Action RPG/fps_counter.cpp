#include "fps_counter.h"


void fps_counter::update()
{
	float fpsThisFrame = getFPS(fpsClock.restart());
	frameTimes += fpsThisFrame;

	fpsCount++;

	if (fpsClock2.getElapsedTime().asSeconds() >= 1) {
		std::cout << frameTimes / fpsCount << std::endl;
		frameTimes = 0;
		fpsCount = 0;
		fpsClock2.restart();
		frameCount++;
	}
}

float fps_counter::getFPS(const Time& time)
{
	return (1000000.0f / time.asMicroseconds());
}
