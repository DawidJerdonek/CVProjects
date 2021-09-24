#include "Gameplay.h"
#include "Game.h"

Gameplay::Gameplay()
{
	initialise();
	checkCell();
}

Gameplay::~Gameplay()
{
}

void Gameplay::initialise() // initialising the gameplay class
{
	if (!m_backgroundImageTexture.loadFromFile("./resources/images/gameplayBackground.png"))
	{
		std::cout << "Background Image couldn't be loaded!" << std::endl;
	}

	m_backgroundImage.setTexture(m_backgroundImageTexture);
	m_backgroundImage.setScale(0.9, 0.8);

	if (!m_textFont.loadFromFile("./resources/fonts/BrightStar.ttf"))
	{
		std::string s("Error loading font");
		throw std::exception(s.c_str());
	}
	m_scoreText.setFont(m_textFont);

	m_player.initialise();

}

void Gameplay::processInput(sf::Event t_event, sf::RenderWindow& t_window)
{

	if (sf::Event::KeyPressed == t_event.type)
	{
		if (sf::Keyboard::Escape == t_event.key.code)
		{
			t_window.close();
		}
	}
}

void Gameplay::update(double dt, sf::RenderWindow& t_window, int t_character)
{

	m_chosenCharacter = t_character;
	m_bullet.update(dt, m_player, t_window);
	m_player.update(dt, m_chosenCharacter);
	m_enemy.update();
	m_particles.Update();
	m_particleSystem.Update();
	checkForCollisionWithPlayer();
	checkForCollisionWithBullet();
	checkForCollisionWithWalls();
	checkForAliveEnemies();

	if (!m_enemy.traversableCells.empty())
	{
		for (int i = 0; i < 3; i++)
		{
			if (m_enemy.isEnemyMoving)
			{
				if (m_enemy.isDestinationReached == false)
				{
					if (!m_enemy.foundNextPosition)
					{
						m_enemy.currentRow[i] = m_enemy.traversableCells.at(m_enemy.traversableCells.size() - 1) / 10;
						m_enemy.currentCol[i] = m_enemy.traversableCells.at(m_enemy.traversableCells.size() - 1) % 10;

						//m_enemy.pos = arr[m_enemy.currentCol[i]][m_enemy.currentRow[i]].getPosition();
						//m_enemy.pos.x += (arr[m_enemy.currentCol[i]][m_enemy.currentRow[i]].getSize().x / 2);
						//m_enemy.pos.y += (arr[m_enemy.currentCol[i]][m_enemy.currentRow[i]].getSize().x / 2);

						//m_velocity = (m_enemy.pos - m_player.m_playerSprite.getPosition());

						//v = m_speed

						m_enemy.foundNextPosition = true;
					}
					//m_player.m_playerSprite.setPosition(m_player.m_playerSprite.getPosition() + v);

					//if (thor::length(m_player.m_playerSprite.getPosition() - pos) <= 0.25f)
					//{
						//m_enemy.foundNextPosition = false;
						//m_enemy.traversableCells.pop_back();
					//}
				}
			}
		}
	}
	else
	{
		m_enemy.isEnemyMoving = false;
	}


	m_scoreText.setString("SCORE: " + std::to_string(m_score));
	m_scoreText.setPosition(600,20);
	m_scoreText.setFillColor(sf::Color::White);

	
}

void Gameplay::checkCell() // method for tracking the used cells 
{
	for (int i = 0; i < 3; i++)
	{
		int cellOfPlayer, cellOfCurrentEnemy;

		for (int index = 0; index < 100; index++)
		{
			if (m_player.m_playerSprite.getGlobalBounds().intersects(m_grid.returnCell(index).getRect().getGlobalBounds()))
			{
				cellOfPlayer = index;
			}

			if (m_enemy.m_enemySprites[i].getGlobalBounds().intersects(m_grid.returnCell(index).getRect().getGlobalBounds()))
			{
				cellOfCurrentEnemy = index;
			}
		}


	m_enemy.traversableCells.push_back(m_grid.breadthSearch(cellOfCurrentEnemy, cellOfPlayer));
	while (m_enemy.traversableCells.at(m_enemy.traversableCells.size() - 1) != cellOfPlayer)
	{
		m_enemy.traversableCells.push_back(m_grid.breadthSearch(cellOfPlayer, m_enemy.traversableCells.at(m_enemy.traversableCells.size() - 1)));
	}
	m_enemy.traversableCells.pop_back();

	m_enemy.isEnemyMoving = true;
	m_enemy.traversableCells.size();
	}
}

void Gameplay::checkForPlayerLives() // checking how many lives does the player have
{
	if (m_player.returnNumberOfLives() <= 0)
	{
		Game::currentGameState = GameState::EnemyWon;
	}
}

void Gameplay::checkForCollisionWithPlayer() // checking if enemy collided with the player
{
	for (int i = 0; i < 3; i++)
	{
		if (m_player.m_playerSprite.getGlobalBounds().intersects(m_enemy.m_enemySprites[i].getGlobalBounds()))
		{
			m_particleSystem.Initialise(m_player.getPlayerPosition());
			m_player.decrementNumberOfLives();
			m_player.playerDeath();
			m_enemy.decrementNumberOfLives();
			//m_enemy.resetEnemyPosition();
			checkForPlayerLives();
		}
	}
	}
	

void Gameplay::checkForCollisionWithBullet() // checking if the bullet collided with enemy
{
	sf::Vector2f projectile = m_bullet.getProjectile();
	for (int i = 0; i < 3; i++)
	{
		sf::Vector2f checkLength = projectile - m_enemy.m_enemySprites[i].getPosition();
		if (sqrtf(checkLength.x * checkLength.x + checkLength.y * checkLength.y) <= 55.0f && m_bullet.m_bulletFired == true)
		{
			m_particleSystem.Initialise(m_enemy.getEnemyPosition(i));
			m_score++; //Decrement health if bullet hits enemy
			m_bullet.m_laserPointer.clear();
			m_bullet.m_bulletFired = false; //Allow player to shoot again
			m_enemy.enemyID = i;
			m_enemy.decrementNumberOfLives();
		}
	}
}

void Gameplay::checkForCollisionWithWalls() // checking if the player collided with the wall
{
	for (int i = 0; i < m_obstacle.m_numberOfObstacles; i++)
	{
		if (m_player.m_playerSprite.getGlobalBounds().intersects(m_obstacle.m_obstacles[i].getGlobalBounds()))
		{
			m_player.m_speed = 0.0f;
		}
	}
	
}

void Gameplay::checkForAliveEnemies() // method for checking if all the enemies are alive
{
	if (m_enemy.m_enemyLives[0] <= 0 && m_enemy.m_enemyLives[1] <= 0 && m_enemy.m_enemyLives[2] <= 0)
	{
		Game::currentGameState = GameState::PlayerWon;
		std::cout << "You win hehe xD" << std::endl;
	}
}

void Gameplay::render(sf::RenderWindow& t_window) // drawing everything on screen
{
	t_window.clear(sf::Color(0, 0, 0, 0));
	t_window.draw(m_backgroundImage);
	m_grid.render(t_window);
	t_window.draw(m_scoreText);
	m_bullet.render(t_window);
	m_player.render(t_window);
	m_enemy.render(t_window);
	m_obstacle.render(t_window);
	m_particles.Draw(t_window);
	m_particleSystem.Draw(t_window);
}
