#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <ctime>

class Obstacles {
public:
	Obstacles();
	~Obstacles();

	void initialise();

	void setObstaclePositions();
	void render(sf::RenderWindow& t_window);

	static const int m_numberOfObstacles = 32;
	sf::Sprite m_obstacles[m_numberOfObstacles];
protected:
	

	sf::Texture m_obstacleTexture;
};