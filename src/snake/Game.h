#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "Player.h"

class Game
{
private:
	sf::RenderWindow mWindow;
	Player mPlayer;

	const std::string mGrassImage = "assets/top-view-artificial-grass.jpg";

	void processEvents();
	void update();
	void render();

public:
	Game();
	void run();
};
