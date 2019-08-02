#include "Player.h"



Player::Player(String File, float X, float Y)
{
	texture.loadFromFile("source/img/"+ File);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 63, 66, 66));
	x = X;
	y = Y;
	sprite.setPosition(X, Y);

	direction = "STOP";
}

void Player::motion(string b, float time)
{
	if (b == "STOP")
	{
		dx = 0;
		dy = 0;
	}
	else if (b == "TELEPORT")
	{
		x = 0;
		y = 0;
		sprite.setPosition(x, y);
		direction = "STOP";
		return;
	}
	else if (b == "UP")
	{
		speed = 0.1; dx = 0; dy = -speed;
	}
	else if (b == "DOWN")
	{
		speed = 0.1; dx = 0; dy = speed;
	}
	else if (b == "LEFT")
	{
		speed = 0.1; dx = -speed; dy = 0; 
	}
	else if (b == "RIGHT")
	{
		speed = 0.1; dx = speed; dy = 0;
	}


	x += dx * time;
	y += dy * time;

	//cout << P_X << "  " << P_Y << endl;
	speed = 0;
	sprite.setPosition(x, y);
	direction = "STOP";
}

float Player::pl_x()
{
	return x;
}
float Player::pl_y()
{
	return y;
}

Player::~Player()
{
}
