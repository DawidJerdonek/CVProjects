#include "Game.h"
#include <iostream>

// Updates per milliseconds
static double const MS_PER_UPDATE = 10.0;
GameState Game::currentGameState = GameState::MainMenu;

Game::Game()
	: m_window(sf::VideoMode(ScreenSize::s_width, ScreenSize::s_height, 32), "Joint Project", sf::Style::Default)
{
	m_window.setVerticalSyncEnabled(true);

	initialiseFont();

	//Initialise Sounds

	if (!m_menuMusic.openFromFile("./resources/audio/GalaxyTheme.wav")) // main menu music
	{
		std::string s("Error loading music");
		throw std::exception(s.c_str());
	}
	if (!m_gameMusic.openFromFile("./resources/audio/IllusiveMan.wav")) // game music
	{
		std::string s("Error loading music");
		throw std::exception(s.c_str());
	}
	m_menuMusic.play();
	m_gameMusic.play();
	m_gameMusic.pause();
}

void Game::run() // initialising the game
{
	sf::Clock clock;
	sf::Int32 lag = 0;

	m_mainMenu.initialise(m_textFont);
	m_helpScreen.displayHelp(m_textFont);
	m_choose.initialise(m_textFont);
	m_ending.initialise(m_textFont);

	while (m_window.isOpen())
	{
		sf::Time dt = clock.restart();

		lag += dt.asMilliseconds();

		processEvents();

		while (lag > MS_PER_UPDATE)
		{
			update(lag);
			lag -= MS_PER_UPDATE;
		}
		update(lag);

		render();
	}
}

void Game::initialiseFont()
{
	if (!m_textFont.loadFromFile("./resources/fonts/BrightStar.ttf"))
	{
		std::string s("Error loading font");
		throw std::exception(s.c_str());
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}

		switch (currentGameState)
		{
		case GameState::HelpScreen:
			m_helpScreen.processInput(event);
			break;
		case GameState::CharacterChoice:
			m_choose.processInput(event);
			break;
		case GameState::Gameplay:
			m_gameplay.processInput(event, m_window);
		default:
			break;
		}

		processGameEvents(event);
	}
}

void Game::processGameEvents(sf::Event& event)
{
	// check if the event is a a mouse button release
	//if (sf::Event::KeyPressed == event.type)
	//{
	//	switch (event.key.code)
	//	{
	//	case sf::Keyboard::Escape:
	//		m_window.close();
	//		break;
	//	case sf::Keyboard::Up:
	//		// Up key was pressed...
	//		break;
	//	default:
	//		break;
	//	}
	//}
}

void Game::update(double dt) // updating all the gamestates
{

	switch (currentGameState)
	{

	case GameState::MainMenu:
		m_mainMenu.update(dt, m_window);
		break;
	case GameState::HelpScreen:
		m_helpScreen.update(dt);
		break;
	case GameState::CharacterChoice:
		m_choose.update(dt, m_window);
		break;
	case GameState::Gameplay:
		m_menuMusic.pause();
		m_gameplay.update(dt, m_window, m_choose.characterChosen);
		break;
	case GameState::EnemyWon:
		m_ending.update(dt);
		break;
	case GameState::PlayerWon:
		m_ending.update(dt);
		break;
	default:
		break;
	}
}

void Game::render() // drawing everything on screen
{
	m_window.clear(sf::Color(0, 0, 0, 0));
	switch (currentGameState)
	{
	case GameState::MainMenu:
		m_mainMenu.render(m_window);
		break;
	case GameState::HelpScreen:
		m_helpScreen.render(m_window);
		break;
	case GameState::CharacterChoice:
		m_choose.render(m_window);
		break;
	case GameState::Gameplay:
		m_gameplay.render(m_window);
	case GameState::EnemyWon:
		m_ending.render(m_window);
		break;
	case GameState::PlayerWon:
		m_ending.render(m_window);
	default:
		break;
	}
	m_window.display();
}
