#pragma once
#define maxParticles 50
#include <iostream>
#include <SFML\Graphics.hpp>

class Particles {
public: 

	int timetoLive;
	sf::Vector2f velocity;
	sf::RectangleShape shape;

	void Draw(sf::RenderWindow& win) 
	{ 
		if (timetoLive > 0) 
		{ 
			win.draw(shape);
		} 
	} 
	
	void Update() 
	{
		if (timetoLive > 0) 
		{
			shape.move(velocity);
			timetoLive--;
		}
	} 
	
	Particles() {} 
	Particles(sf::Vector2f pos, sf::Vector2f vel) 
	{
		shape.setSize(sf::Vector2f(6, 6));
		shape.setPosition(pos);
		shape.setFillColor(sf::Color::Red);

		velocity = vel;
		//timetoLive = 200;
		timetoLive = rand() % 150;
	}
};

class ParticleSystem {
public: 
	Particles particles[maxParticles];
	sf::Vector2f position;
	
	void Initialise(sf::Vector2f pos)
	{ 
		position = pos;
		for (int i = 0; i < maxParticles; i++)
		{ 
			particles[i] = Particles(position, sf::Vector2f(rand() / double(RAND_MAX) * 4 - 2, rand() / double(RAND_MAX) * 4 - 2));
		} 
	} 

	void Update() 
	{
		for (int i = 0; i < maxParticles; i++) {
			particles[i].Update();
		}
	} 
	void Draw(sf::RenderWindow& win) 
	{ 
		for (int i = 0; i < maxParticles; i++)
		{ 
			particles[i].Draw(win);
		} 
	} 
	ParticleSystem() {}
};