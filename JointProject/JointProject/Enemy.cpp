#include "Enemy.h"
Enemy::Enemy()
{
	initialise();
}
Enemy::~Enemy()
{
}

void Enemy::initialise()
{
	//Load the texture
	if (!m_enemyTexture.loadFromFile("./resources/images/enemy-sprite.png"))
	{
		std::cout << "Error Loading the Enemy Texture" << std::endl;
	}
	//Set textures origins and positions
	for (int i = 0; i < 3; i++)
	{
		m_enemySprites[i].setTexture(m_enemyTexture);
		m_enemySprites[i].setOrigin(77.25, 71.665);
	}
	m_enemySprites[0].setPosition(650, 100);
	m_enemySprites[1].setPosition(650, 800);
	m_enemySprites[2].setPosition(1350, 500);

	//Set elapsed time and the animation fram to 0
	totalElapsed = 0;
	animationframe = 0;
}

void Enemy::update()
{
	checkNumberOfLives();
	enemyMovement();

	//Go through frames
	totalElapsed++;
	if (totalElapsed > 22)
	{
		totalElapsed = 0;
		animationframe++;
		if (animationframe > 40)
		{
			animationframe = 0;
		}
	}
	//Setup the proper frame
	int col = animationframe % 4;
	int row = animationframe % 6;
	sf::IntRect rectSourceSprite;
	rectSourceSprite.height = 154.5;
	rectSourceSprite.width = 143.33;
	rectSourceSprite.left = row * rectSourceSprite.width;
	rectSourceSprite.top = 2 * rectSourceSprite.height;
	//Set texture rect for all 3 enemies
	for (int i = 0; i < 3; i++)
	{
		m_enemySprites[i].setTextureRect(rectSourceSprite);
	}
}

void Enemy::render(sf::RenderWindow& t_window)
{
	//Draw all the sprites
	for (int i = 0; i < 3; i++)
	{
		t_window.draw(m_enemySprites[i]);
	}
	
}

void Enemy::enemyMovement()
{
	//Setup movement without pathfinding
	for (int i = 0; i < 3; i++)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			m_enemySprites[i].move(0, -3);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			m_enemySprites[i].move(0, 3);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			m_enemySprites[i].move(-3, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			m_enemySprites[i].move(3, 0);
		}
	}
	
}

void Enemy::setEnemyPosition(sf::Vector2f m_enemyPosition)
{
	//Set when pathfinding implemented
	for (int i = 0; i < 3; i++)
	{
		m_enemySprites[i].setPosition(m_enemyPosition);
	}
	
}

void Enemy::checkNumberOfLives()
{
	//Check number of lives for each enemy
	for (int i = 0; i < 3; i++)
	{
		if (m_enemyLives[i] <= 0)
		{
			m_enemySprites[i].setPosition(5000, 5000);
		}
	}
	
}
