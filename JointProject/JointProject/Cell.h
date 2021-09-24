#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "ScreenSize.h"

class Cell {
public:
	Cell();
	~Cell();

	Cell(sf::Vector2f t_position, int t_cellID);
	void mark(bool t_marked);
	void addNeighbour(int t_cellID);
	void setParentCell(int t_cell);
	bool checkMark();
	int returnID();
	int returnParentCell();
	std::vector<int>& neighbours();
	void render(sf::RenderWindow& t_window);
	sf::RectangleShape getRect();

protected:
	int m_parentCellId;
	int m_id;
	int m_previousCellId;
	bool m_marked = false;
	bool m_isPassable;

	int m_centreX;
	int m_centreY;

	std::vector<int> m_neighbours;

	sf::RectangleShape m_shape;

	//int cellId = std::floor(wallx / cell width) + std::floor(wally / cell height) * number of cols);
};
