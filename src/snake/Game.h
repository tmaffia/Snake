#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Game
{
private:
	sf::RenderWindow mWindow;
	sf::Texture mPlayerTexture;
	sf::Sprite mPlayer;

	bool mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight;
	const std::string mGrassImage = "assets/top-view-artificial-grass.jpg";
	const std::string mPlayerImage = "assets/player_50.png";


	void processEvents();
	void update();
	void render();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

public:
	const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

	Game();
	void run();
};
