#include "Obstacles.h"

Obstacles::Obstacles() // constructor
{
	initialise();
}

Obstacles::~Obstacles() // destructor
{
}

void Obstacles::initialise() // initialises the obstacles 
{
	srand(time(nullptr));
	if (!m_obstacleTexture.loadFromFile("./resources/images/wall.png")) // loads in the png file into a texture
	{
		std::cout << "Error Loading the Enemy Texture" << std::endl;
	}
	for (int i = 0; i < m_numberOfObstacles; i++) // setting up all the obstacles
	{

		m_obstacles[i].setTexture(m_obstacleTexture);
		m_obstacles[i].setOrigin(135,135);
		m_obstacles[i].setScale(0.4, 0.4);
	}
	setObstaclePositions();

}

void Obstacles::setObstaclePositions() // setting the positions for all the obstacles
{
	m_obstacles[0].setPosition(300,330);
	m_obstacles[1].setPosition(400,330);
	m_obstacles[2].setPosition(200,330);
	m_obstacles[3].setPosition(100,330);
	m_obstacles[4].setPosition(430,330);
	m_obstacles[5].setPosition(430,230);
	m_obstacles[6].setPosition(430,130);
	m_obstacles[7].setPosition(430,630);
	m_obstacles[8].setPosition(430,730);
	m_obstacles[9].setPosition(430,830);
	m_obstacles[10].setPosition(400,630);
	m_obstacles[11].setPosition(300, 630);
	m_obstacles[12].setPosition(200, 630);
	m_obstacles[13].setPosition(100, 630);

	m_obstacles[14].setPosition(900, 330);
	m_obstacles[15].setPosition(1000, 330);
	m_obstacles[16].setPosition(1100, 330);
	m_obstacles[17].setPosition(1200, 330);
	m_obstacles[18].setPosition(1300, 330);
	m_obstacles[19].setPosition(1340, 330);
	m_obstacles[20].setPosition(800, 330);
	m_obstacles[21].setPosition(800, 230);
	m_obstacles[22].setPosition(800, 130);
	m_obstacles[23].setPosition(800, 830);
	m_obstacles[24].setPosition(800, 730);
	m_obstacles[25].setPosition(800, 630);
	m_obstacles[26].setPosition(900, 630);
	m_obstacles[27].setPosition(1000, 630);
	m_obstacles[28].setPosition(1100, 630);
	m_obstacles[29].setPosition(1200, 630);
	m_obstacles[30].setPosition(1300, 630);
	m_obstacles[31].setPosition(1340, 630);
	

}

void Obstacles::render(sf::RenderWindow& t_window) // drawing the obstacles on screen
{
	for (int i = 0; i < m_numberOfObstacles; i++)
	{
		t_window.draw(m_obstacles[i]);
	}
}
