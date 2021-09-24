#pragma once
#include <SFML/Graphics.hpp>


class CharacterChoice
{
public:
	CharacterChoice();
	~CharacterChoice();

	void initialise(sf::Font& t_font);
	void render(sf::RenderWindow& t_window);
	void update(double t_deltaTime, sf::Window& t_window);
	void processInput(sf::Event t_event);

	int characterChosen = 0;

protected:
	static const int m_options{ 3 };


	bool m_escape = false;

	sf::Texture m_characterYellow;
	sf::Texture m_characterCyan;
	sf::Texture m_characterMagenta;
	sf::Sprite m_characterSprites[m_options]; // array of the options for characters 

	sf::Texture m_halfLife;
	sf::Texture m_fireHowl;
	sf::Texture m_valour;
	sf::Sprite m_logos[m_options];

	sf::Texture m_background;
	sf::Sprite m_backgroundSprite;

	sf::Texture m_healthMenuTexture;
	sf::Sprite m_healthMenu;
	sf::Texture m_healthMenu2Texture;
	sf::Sprite m_healthMenu2;
	sf::Texture m_healthMenu1Texture;
	sf::Sprite m_healthMenu1;

	sf::RectangleShape m_selectionOne;
	sf::RectangleShape m_selectionTwo;
	sf::RectangleShape m_selectionThree;

	sf::Text m_halfLifeDescription; 
	sf::Text m_fireHowlDescription;
	sf::Text m_valourDescription;


};

