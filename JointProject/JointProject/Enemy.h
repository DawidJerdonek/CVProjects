#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <ctime>
#include "Grid.h"


class Enemy {
public:
	Enemy();
	~Enemy();

	void initialise();
	void update();
	void render(sf::RenderWindow& t_window);
	void enemyMovement();
	void setEnemyPosition(sf::Vector2f m_enemyPosition);
	void checkNumberOfLives();
	void decrementNumberOfLives() { m_enemyLives[enemyID]--;}
	int returnNumberOfLives() { 
		for (int i = 0; i < 3; i++)
		{
			return m_enemyLives[i];
		}
	}
	sf::Vector2f getEnemyPosition(int t_enemy) { 
			return m_enemySprites[t_enemy].getPosition();
	}
	void resetEnemyPosition() { 
		for (int i = 0; i < 3; i++)
		{
			m_enemySprites[i].setPosition(m_enemyPosition);
		}
	};

	sf::Sprite returnSprite() { 
		for (int i = 0; i < 3; i++)
		{
			return m_enemySprites[i];
		}
	};

	sf::Sprite m_enemySprites[3];

	bool isEnemyMoving = false;
	bool isDestinationReached = false;
	bool foundNextPosition = false;

	std::vector<int> traversableCells;

	int currentRow[2];
	int currentCol[2];
	int enemyID = 0;
	sf::Vector2f pos{};
	int m_enemyLives[3]{ 3,3,3 };
protected:
	int totalElapsed = 0;
	int animationframe = 0;


	
	sf::Sprite m_enemyLivesSprites[3];

	sf::Vector2f m_enemyPosition{ 900,600 };
	sf::Texture m_enemyTexture;
};
