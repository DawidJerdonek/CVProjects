#pragma once
#include <SFML/Graphics.hpp>

class GameEnd
{

public:
	GameEnd();
	~GameEnd();
	void initialise(sf::Font& t_font);
	void update(double dt);
	void render(sf::RenderWindow& t_window);

protected:

	sf::Font m_font;
	sf::Text m_endText;
};

