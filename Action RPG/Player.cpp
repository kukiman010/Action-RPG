#include "Player.h"



Player::Player(String File, float X, float Y)
{
	texture.loadFromFile("source/img/"+ File);
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, 66, 66));
	x = X;
	y = Y;
	sprite.setPosition(X, Y);

	CurrentFrame = 0;
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
		speed = 0.1; 
		dx = 0; 
		dy = -speed;
	}
	else if (b == "DOWN")
	{
		speed = 0.1; 
		dx = 0; 
		dy = speed;
	}
	else if (b == "LEFT")
	{
		speed = 0.1; 
		dx = -speed; 
		dy = 0; 
	}
	else if (b == "RIGHT")
	{
		speed = 0.1; 
		dx = speed; 
		dy = 0;
	}
	animation(time);


	x += dx * time;
	y += dy * time;

	
	speed = 0;
	sprite.setPosition(x, y);
	direction = "STOP";
}

void Player::animation(float time)
{
	const int up = 261;
	const int down = 67;
	const int left = 131;
	const int right = 194;

	CurrentFrame += 0.002 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
	if (CurrentFrame > 4)
		CurrentFrame -= 4;

	if (direction == "UP")
		sprite.setTextureRect(IntRect(65 * int(CurrentFrame), up, 66, 66)); 
	else if (direction == "DOWN")
		sprite.setTextureRect(IntRect(65 * int(CurrentFrame), down, 66, 66)); 
	else if (direction == "LEFT")
		sprite.setTextureRect(IntRect(65 * int(CurrentFrame), left, 66, 66));
	else if (direction == "RIGHT")
		sprite.setTextureRect(IntRect(65 * int(CurrentFrame), right, 66, 66));

	
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
