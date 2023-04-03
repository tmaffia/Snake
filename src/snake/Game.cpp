#include "Game.h"

Game::Game()
	: mWindow(sf::VideoMode(640, 480), "Snake")
	, mPlayer()
{
	mWindow.setFramerateLimit(60);

	if (!mPlayerTexture.loadFromFile(mPlayerImage))
		std::cout << "Error Loading Player Texture" << std::endl;
	mPlayer.setTexture(mPlayerTexture);
	mPlayer.setPosition(100.f, 100.f);
}

void Game::run()
{
	while (mWindow.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void Game::update()
{
	sf::Vector2f movement(0.f, 0.f);
	if (mIsMovingUp)
		movement.y -= 3.f;
	if (mIsMovingDown)
		movement.y += 3.f;
	if (mIsMovingLeft)
		movement.x -= 3.f;
	if (mIsMovingRight)
		movement.x += 3.f;

	mPlayer.move(movement);
}

void Game::render()
{

	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
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