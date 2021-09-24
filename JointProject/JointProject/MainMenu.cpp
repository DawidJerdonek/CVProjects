#include "MainMenu.h"
#include "Game.h"
#include <iostream> 

MainMenu::MainMenu()
{

}

MainMenu::~MainMenu()
{
}

void MainMenu::initialise(sf::Font& t_font)
{

	if (!m_playerTexture.loadFromFile("./resources/images/player-sprite-blue.png")) // loading in the player texture for the main menu
	{
		std::cout << "Error loading image" << std::endl;
	}
	m_playerSprite.setTexture(m_playerTexture);///////////////////////////////////////////////////////////////////////////////////////////////
	sf::IntRect rectSourceSprite;//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	rectSourceSprite.height = 55;/////////////////////////////////////////////////////////
	rectSourceSprite.width = 47.77;/////////////////////////////////////////////////////////           Setting up the player rect for the animation
	rectSourceSprite.left = rectSourceSprite.width;///////////////////////////////////////////////////////////////////////////////////////////////
	rectSourceSprite.top = rectSourceSprite.height;///////////////////////////////////////////////////////////////////////////////////////////////
	m_playerSprite.setTextureRect(rectSourceSprite);///////////////////////////////////////////////////////////////////////////////////////////////
	m_playerSprite.setPosition(500, 500);//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	m_playerSprite.scale(1.9, 1.9);//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	m_rect1.setFillColor(sf::Color::Blue);///////////////////
	m_rect2.setFillColor(sf::Color::Red);///////////////////
	m_rect1.setSize(sizeOfRects);///////////////////
	m_rect2.setSize(sizeOfRects);/////////////////// Setting up moving rectangles on the main menu
	m_rect1.setPosition(570, 400);//////////////////////////////////////
	m_rect2.setPosition(570, 450);//////////////////////////////////////


	m_topOffset = 620;/////////////////// 
	m_verticalSpacing = 100;/////////////////// Setting up the dimensions for the main menu buttons
	m_buttonWidth = 200;///////////////////
	m_leftTopOffset = ((800 - m_buttonWidth) / 2) + 300;      //(Game::s_screenWidth - m_buttonWidth)/2; after game is merged as its not here yet
	m_buttonHeigth = 50;///////////////////
	int textDropOffset = 10;///////////////////
	sf::String m_menuTexts[] = { "PLAY","HELP","EXIT" };

	if (!m_backgroundImageTexture.loadFromFile("./resources/images/backgroundImage.jpg")) // Setting up the background image
	{
		std::cout << "Background Image couldn't be loaded!" << std::endl;
	}
	m_backgroundImage.setTexture(m_backgroundImageTexture);

	if (!m_buttonTexture.loadFromFile("./resources/images/button.png")) // button textures
	{
		std::cout << "error with button file";
	}
	if (!m_buttonWhiteTexture.loadFromFile("./resources/images/buttonWhite.png")) // buttons texture
	{
		std::cout << "error with button file";
	}


	for (int i = 0; i < m_options; i++) // code for attaching textures to buttons and text size
	{
		m_buttonSprites[i].setTexture(m_buttonTexture);
		m_buttonSprites[i].setPosition(m_leftTopOffset, m_verticalSpacing * i + m_topOffset);
		sf::Vector2u textureSize = m_buttonTexture.getSize();
		m_buttonSprites[i].setScale(m_buttonWidth / textureSize.x, m_buttonHeigth / textureSize.y);

		m_buttonText[i].setFont(t_font);
		m_buttonText[i].setString(m_menuTexts[i]);
		m_buttonText[i].setFillColor(sf::Color::White);
		m_buttonText[i].setCharacterSize(18);
		sf::FloatRect textSize = m_buttonText[i].getGlobalBounds();
		float textOffset = (m_buttonWidth - textSize.width *1.5) / 2;
		m_buttonText[i].setPosition(m_leftTopOffset + textOffset, m_verticalSpacing * i + m_topOffset + textDropOffset);
	}

}

void MainMenu::update(double t_deltaTime, sf::Window& t_window)
{
	m_playerSprite.rotate(-1.0);
	m_playerSprite.move(-0.5, -0.7);
	m_rect1.move(movespeed1, 0);
	m_rect2.move(movespeed2, 0);


	if (m_playerSprite.getPosition().y < -50)
	{
		m_playerSprite.setPosition(1200,1000);
	}

	////////////////////////////////////////////////////////////////////// Small boundary bounce for rectangles in the main menu 
	if (m_rect1.getPosition().x < -100)
	{
		movespeed1 = 3;
	}
	if (m_rect2.getPosition().x < -100)
	{
		movespeed2 = 3;
	}
	if (m_rect1.getPosition().x > 1500)
	{
		movespeed1 = -3;
	}
	if (m_rect2.getPosition().x > 1500)
	{
		movespeed2 = -3;
	}
	//////////////////////////////////////////////////////////////////////
	sf::Vector2i mouseLocation;
	mouseLocation = sf::Mouse::getPosition(t_window);
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) // detection of lmb press
	{
		if (mouseLocation.x > m_leftTopOffset&& mouseLocation.x < m_leftTopOffset + m_buttonWidth)
		{
			if (mouseLocation.y > m_topOffset&& mouseLocation.y&& mouseLocation.y < m_topOffset + m_buttonHeigth)
			{
				Game::currentGameState = GameState::CharacterChoice; // changing game states
			}

			if (mouseLocation.y > m_topOffset + m_verticalSpacing && mouseLocation.y < m_topOffset + m_verticalSpacing + m_buttonHeigth)
			{
				Game::currentGameState = GameState::HelpScreen; // changing game states

			}

			if (mouseLocation.y > m_topOffset + m_verticalSpacing * 2 && mouseLocation.y < m_topOffset + m_verticalSpacing * 2 + m_buttonHeigth)
			{
				t_window.close();
			}
		}
	}
	if (mouseLocation.x > m_leftTopOffset&& mouseLocation.x < m_leftTopOffset + m_buttonWidth) // inside this if statement is texture changing on hovering the button
	{
		if (mouseLocation.y > m_topOffset&& mouseLocation.y&& mouseLocation.y < m_topOffset + m_buttonHeigth)
		{
			m_buttonSprites[0].setTexture(m_buttonWhiteTexture);
			m_buttonText[0].setFillColor(sf::Color::Black);
		}
		else 
		{
			m_buttonSprites[0].setTexture(m_buttonTexture);
			m_buttonText[0].setFillColor(sf::Color::White);

		}

		if (mouseLocation.y > m_topOffset + m_verticalSpacing && mouseLocation.y < m_topOffset + m_verticalSpacing + m_buttonHeigth)
		{
			m_buttonSprites[1].setTexture(m_buttonWhiteTexture);
			m_buttonText[1].setFillColor(sf::Color::Black);
		}
		else
		{
			m_buttonSprites[1].setTexture(m_buttonTexture);
			m_buttonText[1].setFillColor(sf::Color::White);

		}
		if (mouseLocation.y > m_topOffset + m_verticalSpacing * 2 && mouseLocation.y < m_topOffset + m_verticalSpacing * 2 + m_buttonHeigth)
		{
			m_buttonSprites[2].setTexture(m_buttonWhiteTexture);
			m_buttonText[2].setFillColor(sf::Color::Black);
		}
		else
		{
			m_buttonSprites[2].setTexture(m_buttonTexture);
			m_buttonText[2].setFillColor(sf::Color::White);

		}
	}
	else // changing the button texture and the text colour
	{
		m_buttonSprites[0].setTexture(m_buttonTexture);
		m_buttonSprites[1].setTexture(m_buttonTexture);
		m_buttonSprites[2].setTexture(m_buttonTexture);
		m_buttonText[0].setFillColor(sf::Color::White);
		m_buttonText[1].setFillColor(sf::Color::White);
		m_buttonText[2].setFillColor(sf::Color::White);
	}


}

void MainMenu::render(sf::RenderWindow& t_window) // drawing everything on the screen
{
	t_window.draw(m_backgroundImage);
	t_window.draw(m_playerSprite);
	t_window.draw(m_rect1);
	t_window.draw(m_rect2);
	for (int i = 0; i < m_options; i++)
	{
		t_window.draw(m_buttonSprites[i]);
		t_window.draw(m_buttonText[i]);
	}
	
}


