#pragma once

#include <SFML\Graphics.hpp>


class MainMenu
{
public:
	MainMenu();
	~MainMenu();

	void initialise(sf::Font& t_font);
	void update(double t_deltaTime, sf::Window& t_window);
	void render(sf::RenderWindow& t_window);


protected:
	
	sf::Texture m_playerTexture;
	sf::Sprite m_playerSprite;

	sf::RectangleShape m_rect1;
	sf::RectangleShape m_rect2;

	int movespeed1 = 3;
	int movespeed2 = -3;


	sf::Vector2f sizeOfRects{ 100, 30 };
	static const int m_options{ 3 }; // number of buttons in the menu 
	sf::Texture m_buttonTexture; // texture backround for buttons
	sf::Texture m_buttonWhiteTexture;
	sf::Texture m_backgroundImageTexture;
	sf::Sprite m_backgroundImage;
	sf::Sprite m_buttonSprites[m_options]; // array of the option buttons
	sf::Font m_font; // reference to the font usent in the whole project
	sf::Text m_buttonText[m_options]; // button texts

	float m_topOffset{ 0.0f }; // top area used for menu
	float m_leftTopOffset{ 0.0f }; // top left area used for menu
	float m_verticalSpacing{ 0.0f }; // gap in the pixels between tops 
	float m_buttonHeigth{ 0.0f }; // heigth of the buttons
	float m_buttonWidth{ 0.0f }; // width of the buttons 

};

