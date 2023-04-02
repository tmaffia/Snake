#pragma once
#include <SFML/Graphics.hpp>

class Game
{
private:
	sf::RenderWindow mWindow;
	sf::RectangleShape mPlayer;
	bool mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight;

	void processEvents();
	void update();
	void render();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

public:
	Game();
	void run();
};
