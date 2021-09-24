#pragma once
#include <SFML\Graphics.hpp>
#include"ScreenSize.h"

class Help
{
public:

	Help();
	~Help();

	void displayHelp(sf::Font& t_font);
	void render(sf::RenderWindow& t_window);
	void update(double t_deltaTime);
	void processInput(sf::Event t_event);


protected:

	ScreenSize size;

	bool m_escape = false;

	sf::Font m_font;
	sf::Text m_help;
	sf::Text m_objective;
};

