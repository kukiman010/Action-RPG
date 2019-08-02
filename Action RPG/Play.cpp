#include "Play.h"



Play::Play()
{
	setup();
	RenderWindow window(sf::VideoMode(width, height), "Action-RPG");
	Player pl("player.png",60,60);
	locations map("floor.png");

	view vi(width, height);
	

	float c_x, c_y;
	c_x = pl.pl_x();
	c_y = pl.pl_y();

	while (window.isOpen())
	{
		time_window = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time_window = time_window / 500;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		

		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			pl.direction = "LEFT";
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			pl.direction = "RIGHT";
		}
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			pl.direction = "UP";
			//snake_1.sprite.move(0, -0.1*time_window);
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			pl.direction = "DOWN";
			//snake_1.sprite.move(0, 0.1*time_window);
		}
		if (Keyboard::isKeyPressed(Keyboard::P))
		{
			pl.direction = "STOP";
		}
		if (Keyboard::isKeyPressed(Keyboard::T))
		{
			pl.direction = "TELEPORT";
		}



		pl.motion(pl.direction, time_window);
		vi.GetPlayerView(pl.pl_x(), pl.pl_y(), width, height);




		window.clear();

		for (int i = 0; i < map.HEIGHT_MAP; i++)
			for (int j = 0; j < map.WIDTH_MAP; j++)
			{
				if (map.TileMap[i][j] == ' ') map.s_map.setTextureRect(IntRect(0, 0, 64, 64)); //если встретили символ пробел, то рисуем 1й квадратик
				if (map.TileMap[i][j] == 's') map.s_map.setTextureRect(IntRect(64, 0, 64, 64));//если встретили символ s, то рисуем 2й квадратик
				if (map.TileMap[i][j] == '0') map.s_map.setTextureRect(IntRect(64, 192, 64, 64));//если встретили символ 0, то рисуем 3й квадратик


				map.s_map.setPosition(j * 64, i * 64);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат
				window.draw(map.s_map);//рисуем квадратики на экран
			}

		window.draw(pl.sprite);
		window.setView(vi.vi);
		window.display();
	}
}

void Play::setup()
{
	width = 400;
	height = 300;
}


Play::~Play()
{
}
