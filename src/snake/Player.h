#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
private:
	sf::Texture mPlayerTexture;
	sf::Sprite mPlayerSprite;
	sf::Vector2f mPlayerVelocity;
	int mLength;
	bool mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight;

	const std::string mPlayerImage = "assets/player_50.png";

public:
	Player();
	const sf::Vector2f& getPlayerPosition();
	sf::Vector2f& getPlayerVelocity();
	sf::Sprite& getPlayerSprite();
	void move(const sf::Vector2f& offset);
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
};