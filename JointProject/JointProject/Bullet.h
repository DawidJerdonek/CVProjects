#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Player.h"
#include <math.h>


class Bullet {
public:
	Bullet();
	~Bullet();

	void initialise();
	void update(double dt, Player t_player, sf::Window& t_window);
	void shoot(double dt, Player t_player, sf::Window& t_window);
	void render(sf::RenderWindow& t_window);
	sf::Vector2f getProjectile() { return m_mobileBullet; };

	sf::Vector2f playerPos;
	sf::VertexArray m_laserPointer{ sf::Lines };

	bool m_bulletFired = false;
protected:

	sf::Vector2f m_mousePoint;
	sf::Vector2f m_direction;
	sf::Vector2f m_unitVector;
	sf::Vector2f m_velocityVector;
	sf::Vector2f m_mobileBullet;

	float m_speed = 15.0f; //Speed of shot
	float m_distance;
	double m_playerRotation;


	//Sounds
	sf::SoundBuffer m_shotBuffer; //Plays when player shoots
	sf::Sound m_playerShot;

};