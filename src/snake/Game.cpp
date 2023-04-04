#include "Game.h"

Game::Game()
	: mWindow(sf::VideoMode(640, 640), "Snake"), mPlayer()
{
	mWindow.setFramerateLimit(60);
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
			mPlayer.handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			mPlayer.handlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void Game::update()
{
	mPlayer.move(mPlayer.getPlayerVelocity());
}


void Game::render()
{
	mWindow.clear();
	mWindow.draw(mPlayer.getPlayerSprite());
	mWindow.display();
}

