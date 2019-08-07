#pragma once
#include <iostream>
#include <conio.h>
#include <ctime>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


using namespace std;
using namespace boost;
using namespace boost::asio;
using namespace sf;

namespace win_info
{
	const int width = 400;
	const int height = 300;
}