#include "Player.h"

Player::Player()
	: mPlayerVelocity(0.f, 0.f), mLength(1)
	, mIsMovingUp(false), mIsMovingDown(false)
	, mIsMovingLeft(false), mIsMovingRight(false)
{
	if (!mPlayerTexture.loadFromFile(mPlayerImage))
		std::cout << "Error Loading Player Texture" << std::endl;
	mPlayerSprite.setTexture(mPlayerTexture);
	mPlayerSprite.setPosition(100.f, 100.f);
}

const sf::Vector2f& Player::getPlayerPosition()
{
	return mPlayerSprite.getPosition();
}

sf::Vector2f& Player::getPlayerVelocity()
{
	mPlayerVelocity = { 0.f, 0.f };
	if (mIsMovingUp)
		mPlayerVelocity.y -= 3.f;
	if (mIsMovingDown)
		mPlayerVelocity.y += 3.f;
	if (mIsMovingLeft)
		mPlayerVelocity.x -= 3.f;
	if (mIsMovingRight)
		mPlayerVelocity.x += 3.f;

	return mPlayerVelocity;
}

sf::Sprite& Player::getPlayerSprite()
{
	return mPlayerSprite;
}

void Player::move(const sf::Vector2f& offset)
{
	mPlayerSprite.move(offset);
}

void Player::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		mIsMovingRight = isPressed;
}
