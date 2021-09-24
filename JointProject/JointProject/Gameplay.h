#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Obstacles.h"
#include "Particles.h"
#include "Grid.h"

class Gameplay
{
public:
	Gameplay();
	~Gameplay();


	bool gameplayLevel = false;

	void initialise();

	void processInput(sf::Event t_event, sf::RenderWindow& t_window);

	void update(double dt, sf::RenderWindow& t_window, int t_character);

	void checkCell();

	void checkForPlayerLives();

	void checkForCollisionWithPlayer();
	void checkForCollisionWithBullet();
	void checkForCollisionWithWalls();

	void checkForAliveEnemies();

	void render(sf::RenderWindow& t_window);

	Player m_player;

	int m_chosenCharacter = 0;

protected:

	int static const ROWNUM = 10;
	int static const COLNUM = 10;

	int m_score = 0;

	int arr[ROWNUM][COLNUM]
	{
		{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 },
		{ 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 },
		{ 20, 21, 22, 23, 24, 25, 26, 27, 28, 29 },
		{ 30, 31, 32, 33, 34, 35, 36, 37, 38, 39 },
		{ 40, 41, 42, 43, 44, 45, 46, 47, 48, 49 },
		{ 50, 51, 52, 53, 54, 55, 56, 57, 58, 59 },
		{ 60, 61, 62, 63, 64, 65, 66, 67, 68, 69 },
		{ 70, 71, 72, 73, 74, 75, 76, 77, 78, 79 },
		{ 80, 81, 82, 83, 84, 85, 86, 87, 88, 89 },
		{ 90, 91, 92, 93, 94, 95, 96, 97, 98, 99 }
	};

	Grid m_grid;
	Enemy m_enemy;
	Bullet m_bullet;
	Obstacles m_obstacle;
	Particles m_particles;
	ParticleSystem m_particleSystem;
	sf::Sprite m_backgroundImage;
	sf::Texture m_backgroundImageTexture;

	sf::Font m_textFont;
	sf::Text m_scoreText;
};

