#include "CharacterChoice.h"
#include "Game.h"
#include <iostream>

CharacterChoice::CharacterChoice()
{

}

CharacterChoice::~CharacterChoice()
{
}

void CharacterChoice::initialise(sf::Font& t_font)
{//////////////////////////////////////////////////////////////////////////////////////// Tips for each character
	m_halfLifeDescription.setFont(t_font);
	m_halfLifeDescription.setCharacterSize(11);
	m_halfLifeDescription.setString("HALFLIFE MODEL:\n \nA MUCH CHEAPER VERSION \nOF THE ORIGINAL MODEL \nIT RETAINS THE FIREPOWER \nBUT HAS WEAKER ARMOUR \nIRONICALLY THIS MODEL IS APPROX. \n33.3% WEAKER THAN THE ORIGINAL, \nNOT HALF LIKE THE NAME SUGGESTS ");
	m_halfLifeDescription.setFillColor(sf::Color::Yellow);
	m_halfLifeDescription.setPosition(490.0f, 720.0f);

	m_fireHowlDescription.setFont(t_font);
	m_fireHowlDescription.setCharacterSize(11);
	m_fireHowlDescription.setString("FIREHOWL MODEL:\n \nAN EVEN CHEAPER VERSION \nOF THE ORIGINAL MODEL \nIT RETAINS THE FIREPOWER \nBUT HAS VERY WEAK ARMOUR \nTHE PRODUCTION COST IS MINIMAL \nTHEY ARE NORMALLY DEPLOYED, \nIN 'PACKS' SIMILAR TO WOLF PACKS");
	m_fireHowlDescription.setFillColor(sf::Color::Magenta);
	m_fireHowlDescription.setPosition(970.0f, 720.0f);


	m_valourDescription.setFont(t_font);
	m_valourDescription.setCharacterSize(11);
	m_valourDescription.setString("VALOUR MODEL:\n \nTHE ORIGINAL MODEL\nOF BATTLE BOT \nIT HAS A HIGH FIREPOWER \nAND HEAVY ARMOUR PLATING \nA DOWNSIDE OF THIS MODEL \nTHE PRODUCTION COST IS HIGH \nUSED FOR SPECIAL OPERATIONS ") ;
	m_valourDescription.setFillColor(sf::Color::Cyan);
	m_valourDescription.setPosition(10.0f, 720.0f);
	//////////////////////////////////////////////////////////////////////////////////////// Tips for each character

	//////////////////////////////////////////////////////////////////////////////////////// Loading in all the textures and setting up the sprites 
	if (!m_background.loadFromFile("./resources/images/ChooseMenu1.png"))
	{
		std::cout << "Error loading image" << std::endl;
	}
	m_backgroundSprite.setTexture(m_background);
	m_backgroundSprite.setPosition(0, 0);

	if (!m_healthMenuTexture.loadFromFile("./resources/images/healthMenu3.png"))
	{
		std::cout << "Error loading image" << std::endl;
	}
	m_healthMenu.setTexture(m_healthMenuTexture);
	m_healthMenu.setPosition(170, 825);
	m_healthMenu.setScale(0.2, 0.2);

	if (!m_healthMenu2Texture.loadFromFile("./resources/images/healthMenu2.png"))
	{
		std::cout << "Error loading image" << std::endl;
	}
	m_healthMenu2.setTexture(m_healthMenu2Texture);
	m_healthMenu2.setPosition(670, 825);
	m_healthMenu2.setScale(0.2, 0.2);

	if (!m_healthMenu1Texture.loadFromFile("./resources/images/healthMenu1.png"))
	{
		std::cout << "Error loading image" << std::endl;
	}
	m_healthMenu1.setTexture(m_healthMenu1Texture);
	m_healthMenu1.setPosition(1170, 825);
	m_healthMenu1.setScale(0.2, 0.2);

	if (!m_characterYellow.loadFromFile("./resources/images/player-sprite-1.png"))
	{
		std::cout << "Error loading image" << std::endl;
	}
	if (!m_characterCyan.loadFromFile("./resources/images/player-sprite-blue-1.png"))
	{
		std::cout << "Error loading image" << std::endl;
	}
	if (!m_characterMagenta.loadFromFile("./resources/images/player-sprite-purple-1.png"))
	{
		std::cout << "Error loading image" << std::endl;
	}

	m_characterSprites[0].setTexture(m_characterYellow);
	m_characterSprites[1].setTexture(m_characterCyan);
	m_characterSprites[2].setTexture(m_characterMagenta);

	m_characterSprites[0].setPosition(600, 500);
	m_characterSprites[0].setScale(4, 4);

	m_characterSprites[1].setPosition(100, 500);
	m_characterSprites[1].setScale(4, 4);

	m_characterSprites[2].setPosition(1100, 500);
	m_characterSprites[2].setScale(4, 4);

	if (!m_halfLife.loadFromFile("./resources/images/halfLife.png"))
	{
		std::cout << "Error loading image" << std::endl;
	}


	if (!m_fireHowl.loadFromFile("./resources/images/Firehowl.png"))
	{
		std::cout << "Error loading image" << std::endl;
	}

	if (!m_valour.loadFromFile("./resources/images/Valour.png"))
	{
		std::cout << "Error loading image" << std::endl;
	}

	m_logos[0].setTexture(m_halfLife);
	m_logos[0].setOrigin(180, 180);
	m_logos[0].setPosition(700, 400);
	m_logos[0].setScale(0.55, 0.55);

	m_logos[1].setTexture(m_valour);
	m_logos[1].setOrigin(180, 180);
	m_logos[1].setPosition(200, 400);
	m_logos[1].setScale(0.6, 0.6);

	m_logos[2].setTexture(m_fireHowl);
	m_logos[2].setOrigin(128, 96);
	m_logos[2].setPosition(1200, 400);
	m_logos[2].setScale(1.05, 1.05);

	m_selectionOne.setFillColor(sf::Color::Transparent);
	m_selectionOne.setOutlineColor(sf::Color::Cyan);
	m_selectionOne.setOutlineThickness(5);
	m_selectionOne.setSize(sf::Vector2f(470, 890));
	m_selectionOne.setPosition(sf::Vector2f(5, 5));

	m_selectionTwo.setFillColor(sf::Color::Transparent);
	m_selectionTwo.setOutlineColor(sf::Color::Yellow);
	m_selectionTwo.setOutlineThickness(5);
	m_selectionTwo.setSize(sf::Vector2f(470, 890));
	m_selectionTwo.setPosition(sf::Vector2f(485, 5));

	m_selectionThree.setFillColor(sf::Color::Transparent);
	m_selectionThree.setOutlineColor(sf::Color::Magenta);
	m_selectionThree.setOutlineThickness(5);
	m_selectionThree.setSize(sf::Vector2f(470, 890));
	m_selectionThree.setPosition(sf::Vector2f(965, 5));
	/////////////////////////////////////////////////////////////////////////////////////// Loading in all the textures and setting up the sprites 

}

void CharacterChoice::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_backgroundSprite);
	t_window.draw(m_selectionOne);
	t_window.draw(m_selectionTwo);
	t_window.draw(m_selectionThree);
	for (int i = 0; i < m_options; i++)
	{
		t_window.draw(m_characterSprites[i]);
		t_window.draw(m_logos[i]);
	}
	t_window.draw(m_halfLifeDescription);
	t_window.draw(m_fireHowlDescription);
	t_window.draw(m_valourDescription);
	t_window.draw(m_healthMenu);
	t_window.draw(m_healthMenu1);
	t_window.draw(m_healthMenu2);
}

void CharacterChoice::update(double t_deltaTime, sf::Window& t_window)
{
	sf::Vector2i mouseLocation;
	mouseLocation = sf::Mouse::getPosition(t_window);

	if (mouseLocation.x > m_selectionOne.getPosition().x && mouseLocation.x < 470) ////////////////////////////////////////// Tracking the user mouse and selecting character
	{
		m_selectionOne.setOutlineColor(sf::Color::Green);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			characterChosen = 1;
			Game::currentGameState = GameState::Gameplay;
		}
	}
	else
	{
		m_selectionOne.setOutlineColor(sf::Color::Cyan);
	}
	if (mouseLocation.x > m_selectionTwo.getPosition().x&& mouseLocation.x < 955)
	{
		m_selectionTwo.setOutlineColor(sf::Color::Green);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			characterChosen = 2;
			Game::currentGameState = GameState::Gameplay;
		}
	}
	else
	{
		m_selectionTwo.setOutlineColor(sf::Color::Yellow);
	}
	if (mouseLocation.x > m_selectionThree.getPosition().x&& mouseLocation.x < 1435)
	{
		m_selectionThree.setOutlineColor(sf::Color::Green);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			characterChosen = 3;

			Game::currentGameState = GameState::Gameplay;
		}
	}
	else
	{
		m_selectionThree.setOutlineColor(sf::Color::Magenta);
	}
	if (m_escape == true)
	{
		Game::currentGameState = GameState::MainMenu;
	}
	m_escape = false;
}////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Tracking the user mouse and selecting character

void CharacterChoice::processInput(sf::Event t_event)
{
	if (sf::Event::KeyPressed == t_event.type)
	{
		if (sf::Keyboard::Escape == t_event.key.code)
		{
			m_escape = true;
		}
	}
}
