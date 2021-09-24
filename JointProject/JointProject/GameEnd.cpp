#include "GameEnd.h"
#include "Game.h"

GameEnd::GameEnd()
{
}

GameEnd::~GameEnd()
{
}

void GameEnd::initialise(sf::Font& t_font)
{
	m_endText.setFont(t_font);
	m_endText.setCharacterSize(24);
	m_endText.setPosition(10.0f, ScreenSize::s_height - 400.0f);

}

void GameEnd::update(double dt)
{
	if (Game::currentGameState == GameState::PlayerWon)
	{
		m_endText.setString("CONGRATULATIONS YOU WON! :) ");
		m_endText.setFillColor(sf::Color::Green);
	}
	else if (Game::currentGameState == GameState::EnemyWon)
	{
		m_endText.setString("YOU UNFORTUNATELY LOST! \n MAKE SURE TO TRY AGAIN :)");
		m_endText.setFillColor(sf::Color::Red);
	}
}

void GameEnd::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_endText);
}
