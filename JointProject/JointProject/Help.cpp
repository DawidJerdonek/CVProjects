#include "Help.h"
#include "Game.h"
#include <iostream>


Help::Help()
{
}

Help::~Help()
{
}

void Help::displayHelp(sf::Font& t_font) // setting up display text, and the font of the text
{
	m_help.setFont(t_font);
	m_help.setCharacterSize(24);
	m_help.setString("HOW TO PLAY: \n MOVE LEFT = A KEY \n MOVE RIGHT = D KEY \n MOVE UP = W KEY \n MOVE DOWN = S KEY\n NAVIGATE THE MOUSE AROUND THE SCREEN TO AIM \n LEFT CLICK TO SHOOT\n \n" );
	m_help.setFillColor(sf::Color::Red);
	m_help.setPosition(10.0f, size.s_height - 400.0f);

	m_objective.setFont(t_font);
	m_objective.setCharacterSize(24);
	m_objective.setString("OBJECTIVE: \n GAIN SCORE BY SHOOTING ENEMIES \n COLLECT POWERS, UPGRADES AND HEALTH SHOTS\n FROM CERTAIN FALLEN ENEMIES \n KEEP YOUR HEALTH ABOVE ZERO \n DEFEAT EACH WAVE OF ENEMIES TO PROCEED\n FURTHER IN THE GAME");
	m_objective.setFillColor(sf::Color::Cyan);
	m_objective.setPosition(10.0f, 50.0f);
}

void Help::render(sf::RenderWindow& t_window) // drawing everything on screen
{
	t_window.draw(m_help);
	t_window.draw(m_objective);
}

void Help::update(double t_deltaTime)
{
	if (m_escape == true) // Checking for the escape button press bool
	{
		Game::currentGameState = GameState::MainMenu;
	}
	m_escape = false;
}

void Help::processInput(sf::Event t_event) // listening to keyboard presses, to detect esc press
{
	if (sf::Event::KeyPressed == t_event.type)
	{
		if (sf::Keyboard::Escape == t_event.key.code)
		{
			m_escape = true;
		}
	}
}
