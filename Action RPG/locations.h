#pragma once
#include "Libres.h"

class locations
{
	Texture t_map;
	
public:
	const int HEIGHT_MAP = 25;//������ ����� ������
	const int WIDTH_MAP = 40;//������ ����� ������	
	Sprite s_map;

	locations(string File);
	string start_map();
	~locations();


	String TileMap[25] = {
		"0000000000000000000000000000000000000000",
		"0                                      0",
		"0   s                                  0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0000000000000000000000000000000000000000",
	};
};

