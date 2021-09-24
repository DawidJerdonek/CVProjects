#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ScreenSize.h"
#include "MainMenu.h"
#include "Help.h"
#include "CharacterChoice.h"
#include "Gameplay.h"
#include "Player.h"
#include "Enemy.h"
#include "GameEnd.h"

enum class GameState
{
	MainMenu,
	HelpScreen,
	CharacterChoice,
	Gameplay,
	EnemyWon,
	PlayerWon
};

class Game
{
public:
	Game();
	void run();

	static GameState currentGameState;
	bool gameplayLevel = false;

protected:

	void initialiseFont();


	void processEvents();

	void processGameEvents(sf::Event&);

	void update(double dt);

	void render();


	MainMenu m_mainMenu;
	Help m_helpScreen;
	Gameplay m_gameplay;
	CharacterChoice m_choose;
	GameEnd m_ending;

	sf::Font m_textFont;

	// main window
	sf::RenderWindow m_window;

	//Set Sounds
	sf::Music m_menuMusic; //Used for background music
	sf::Music m_gameMusic; //Used for background gameplay music
};

