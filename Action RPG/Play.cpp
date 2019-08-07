#include "Play.h"

Play::Play()
{
	Player pl("player.png",60,60);
	locations map("floor.png");
	view vi(win_info::width, win_info::height);
	

	boost::asio::ip::udp::resolver resolver(io_service);
	boost::asio::ip::udp::resolver::query query("127.0.0.1", "80");
	remote_endpoint_ = *resolver.resolve(query);

	ptree root;
	root.put("type", "connection");

	std::ostringstream buf;
	write_json(buf, root, false);
	std::string data = buf.str();

	sock_.open(boost::asio::ip::udp::v4());
	sock_.send_to(boost::asio::buffer(data), remote_endpoint_);

	while (window.isOpen())
	{
		time_window = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time_window = time_window / 500;


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
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			pl.direction = "DOWN";
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
		vi.GetPlayerView(pl.pl_x(), pl.pl_y(), win_info::width, win_info::height);




		window.clear();

		for (int i = 0; i < map.HEIGHT_MAP; i++)
			for (int j = 0; j < map.WIDTH_MAP; j++)
			{
				if (map.TileMap[i][j] == ' ') map.s_map.setTextureRect(IntRect(0, 0, 64, 64)); 
				if (map.TileMap[i][j] == 's') map.s_map.setTextureRect(IntRect(64, 0, 64, 64));
				if (map.TileMap[i][j] == '0') map.s_map.setTextureRect(IntRect(64, 192, 64, 64));


				map.s_map.setPosition(j * 64, i * 64);
				window.draw(map.s_map);
			}

		window.draw(pl.sprite);
		window.setView(vi.vi);
		window.update();


		io_service.poll();
	}
}

void Play::setup()
{
	/*width = 400;
	height = 300;*/
}


