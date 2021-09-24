#include "Player.h"


Player::Player()
{

}

Player::~Player()
{
}

void Player::initialise() // initialising the player Lives textures, the player textures and applying them to the player sprite
{
	if (!m_heartsTexture.loadFromFile("./resources/images/minecraft-heart.png"))
	{
		std::cout << "Error loading image" << std::endl;
	}
	
	int distance = 50;

	for (int i = 0; i < 10; i++)
	{
		m_livesSprites[i].setTexture(m_heartsTexture);
		m_livesSprites[i].setPosition(25 + distance, 50);
		m_livesSprites[i].setOrigin(600,600);
		m_livesSprites[i].setScale(0.1,0.1);
		distance += 50;
	}

	if (!m_playerCyanTexture.loadFromFile("./resources/images/player-sprite-blue.png"))
	{
		std::cout << "Error loading image" << std::endl;
	}
	if (!m_playerYellowTexture.loadFromFile("./resources/images/player-sprite.png"))
	{
		std::cout << "Error Loading the Player Texture" << std::endl;
	}
	if (!m_playerMagentaTexture.loadFromFile("./resources/images/player-sprite-purple.png"))
	{
		std::cout << "Error loading image" << std::endl;
	}

	totalElapsed = 0; // variables for the time elapsed
	animationframe = 0; // variable for the current animation frame

	if (m_characterChosen == 1)
	{
		m_playerSprite.setTexture(m_playerCyanTexture);
	}
	else if (m_characterChosen == 2)
	{
		m_playerSprite.setTexture(m_playerYellowTexture);
	}
	else if (m_characterChosen == 3)
	{
		m_playerSprite.setTexture(m_playerMagentaTexture);
	}
	if (m_characterChosen == 0)
	{
		std::cout << "fail" << std::endl;
	}

	m_playerSprite.setOrigin(27, 31.5);
	m_playerSprite.setScale(2, 2);
	m_playerSprite.setPosition(50, 500);


	if (!m_assemblyLineBuffer.loadFromFile("./resources/audio/Respawn.wav")) // audio for the respawn of the player
	{
		std::string s("Error loading sound");
		throw std::exception(s.c_str());
	}
	m_playerRespawn.setBuffer(m_assemblyLineBuffer);
}

void Player::update(double dt,int t_character)
{

	if (characterSetup == false) // Applying textures to the player sprite depending on choice and setting lives
	{
		m_characterChosen = t_character;
		if (m_characterChosen == 1)
		{
			m_playerSprite.setTexture(m_playerCyanTexture);
			m_lives = 3;
		}
		else if (m_characterChosen == 2)
		{
			m_playerSprite.setTexture(m_playerYellowTexture);
			m_lives = 2;
		}
		else if (m_characterChosen == 3)
		{
			m_playerSprite.setTexture(m_playerMagentaTexture);
			m_lives = 1;
		}
		else
		{
			std::cout << "Character Setup failed" << std::endl;
		}
		characterSetup = true;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////// Setting up the player animation
	totalElapsed++;
	if (totalElapsed > 10)
	{
		totalElapsed = 0;
		animationframe++;
		if (animationframe > 28)
		{
			animationframe = 0;
		}
	}
	int col = animationframe % 4;
	int row = animationframe % 9;
	sf::IntRect rectSourceSprite;
	rectSourceSprite.height = 55; // 
	rectSourceSprite.width = 47.77;
	rectSourceSprite.left = row * rectSourceSprite.width;
	rectSourceSprite.top = 3 * rectSourceSprite.height;
	m_playerSprite.setTextureRect(rectSourceSprite);
	//////////////////////////////////////////////////////////////////////////////////////////////////// 
	movement();

	m_playerSprite.setRotation(m_rotation);

	float radians = (0.01745329252 * m_rotation);

	m_newPlayerPos.x = m_playerSprite.getPosition().x + cos(radians) * m_speed * (dt / 1000);
	m_newPlayerPos.y = m_playerSprite.getPosition().y + sin(radians) * m_speed * (dt / 1000);

	m_playerSprite.setPosition(m_newPlayerPos);

	boundary();
}

void Player::movement() // making the player move and rotating his sprite
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (m_speed < 200.0)
		{
			m_speed += 5;
		}
	}
	else
	{
		if (m_speed > 0)
		{
			m_speed = 0;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		decreaseRotation();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (m_speed > -200.0)
		{
			m_speed -= 5;
		}
	}
	else
	{
		if (m_speed < 0)
		{
			m_speed = 0;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		increaseRotation();
	}

}

void Player::boundary() // player sprite boundary check
{
	if (m_playerSprite.getPosition().x < 30)
	{
		m_playerSprite.setPosition(30 , m_playerSprite.getPosition().y);
	}

	if (m_playerSprite.getPosition().y < 30)
	{
		m_playerSprite.setPosition(m_playerSprite.getPosition().x, 30);
	}

	if (m_playerSprite.getPosition().x > ScreenSize::s_width - 30)
	{
		m_playerSprite.setPosition(ScreenSize::s_width - 30, m_playerSprite.getPosition().y);
	}

	if (m_playerSprite.getPosition().y > ScreenSize::s_height - 30)
	{
		m_playerSprite.setPosition(m_playerSprite.getPosition().x, ScreenSize::s_height - 30);
	}
}

void Player::increaseRotation() // increases player sprite rotation
{
	//m_previousRotation = m_rotation;
	m_rotation += 1;
	if (m_rotation == 360.0)
	{
		m_rotation = 0;
	}
}

void Player::decreaseRotation() // decreases player sprite rotation
{
	//m_previousRotation = m_rotation;
	m_rotation -= 1;
	if (m_rotation == 0.0)
	{
		m_rotation = 359.0;
	}

}

void Player::playerDeath() // identifies if the player has 0 lives
{
	if (m_lives != 0)
	{
		m_playerRespawn.play();
	}
	m_playerSprite.setPosition(50,500);
}

void Player::render(sf::RenderWindow& t_window) // drawing everything to screen
{
	for (int i = 0; i < m_lives; i++)
	{
		t_window.draw(m_livesSprites[i]);
	}
	t_window.draw(m_playerSprite);
}

