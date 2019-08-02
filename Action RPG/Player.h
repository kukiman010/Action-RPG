#pragma once
#include "Libres.h"

class Player
{
private:
	int hp;
	int exp;
	float dx, dy, speed;
	float x, y;
	Texture texture;
	float CurrentFrame;
public:
	Sprite sprite;
	string direction;

	Player(String File, float X, float Y);
	void motion(string b, float time);
	float pl_x();
	float pl_y();
	void animation(float time);
	~Player();
};

