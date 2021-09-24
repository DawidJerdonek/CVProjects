#include "Bullet.h"

Bullet::Bullet()
{
	initialise();
}

Bullet::~Bullet()
{
}

void Bullet::initialise()
{
	//Load in sound of shot
	if (!m_shotBuffer.loadFromFile("./resources/audio/shoot2.wav"))
	{
		std::string s("Error loading sound");
		throw std::exception(s.c_str());
	}
	m_playerShot.setBuffer(m_shotBuffer); //Set sound of shot
}

void Bullet::update(double dt, Player t_player, sf::Window& t_window)
{
	shoot(dt,t_player,t_window); 
}

void Bullet::shoot(double dt, Player t_player, sf::Window& t_window)
{
	sf::Vector2i mouseLocation;
	mouseLocation = sf::Mouse::getPosition(t_window); //Get mouse position

	playerPos = t_player.getPlayerPosition();

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && m_bulletFired == false)
	{
		m_mousePoint = { static_cast<float>(mouseLocation.x),static_cast<float>(mouseLocation.y) };
		std::cout << m_mousePoint.x << m_mousePoint.x << std::endl;
		m_direction = m_mousePoint - playerPos; // setup a direction variable in which the projectile will travel

		m_distance = sqrtf(m_direction.x * m_direction.x + m_direction.y * m_direction.y); //Calculate the length between two points 
		m_unitVector = sf::Vector2f{ m_direction.x / m_distance , m_direction.y / m_distance }; //Calculate unit vector
		m_direction = m_unitVector; //Set the direction properly


		m_velocityVector = m_direction * m_speed;
		m_mobileBullet = playerPos;

		m_bulletFired = true;
	}

	if (m_bulletFired == true)
	{
		m_playerShot.play(); //Play sound
		m_mobileBullet += m_velocityVector; //Add velocity to the current position of projectile tip
		m_laserPointer.clear(); //Ensure the previous shot is cleared

		//Draw the line
		sf::Vertex begin{ playerPos,sf::Color::Transparent };
		m_laserPointer.append(begin);
		sf::Vertex end{ m_mobileBullet, sf::Color::Green };
		m_laserPointer.append(end);

		sf::Vector2f checkLength = m_mobileBullet - m_mousePoint; //check lenght

		if (sqrtf(checkLength.x * checkLength.x + checkLength.y * checkLength.y) <= 8.0f) //get length between two points
		{
			m_laserPointer.clear();
			m_bulletFired = false;
		}

	}
}

void Bullet::render(sf::RenderWindow& t_window) // drawing the laser on screen
{
	t_window.draw(m_laserPointer);
}

