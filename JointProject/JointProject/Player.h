#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML\Audio.hpp>
#include "ScreenSize.h"
#include "CharacterChoice.h"


class Player
{
public:
	Player();
	~Player();

	void initialise();
	void update(double dt, int t_character);
	void movement();
	void boundary();
	void increaseRotation();
	void decreaseRotation();
	void playerDeath();

	void render(sf::RenderWindow& t_window);

	sf::Vector2f getPlayerPosition() { return m_playerSprite.getPosition(); };

	double getRotation() { return m_playerSprite.getRotation(); };

	void decrementNumberOfLives() { m_lives--; }
	int returnNumberOfLives() { return m_lives; }
	sf::Sprite returnSprite() { return m_playerSprite; };

	sf::Sprite m_playerSprite;

	int m_characterChosen = 1;
	double m_speed = 0.0;
protected:
	static const int m_options{ 3 };

	int totalElapsed = 0;
	int animationframe = 0;

	double m_previousRotation = 0.0;
	double m_rotation = 0.0;
	

	bool characterSetup = false;

	sf::Vector2f m_newPlayerPos;

	int m_lives = 3;
  
	sf::Sprite m_livesSprites[10];
	sf::Texture m_heartsTexture;

	sf::Texture m_playerYellowTexture;
	sf::Texture m_playerCyanTexture;
	sf::Texture m_playerMagentaTexture;

	sf::SoundBuffer m_assemblyLineBuffer; //Plays after the dies and is respawned
	sf::Sound m_playerRespawn;

};

