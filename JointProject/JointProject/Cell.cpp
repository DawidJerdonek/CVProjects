#include "Cell.h"

Cell::Cell()
{

}

Cell::~Cell()
{
}

Cell::Cell(sf::Vector2f t_position, int t_cellID) // setting the size of the cell
{
	m_id = t_cellID;
	m_shape.setSize(sf::Vector2f(ScreenSize::s_width / 10, ScreenSize::s_height / 10));
	m_shape.setFillColor(sf::Color::Transparent);
	m_shape.setOutlineColor(sf::Color::Red);
	m_shape.setOutlineThickness(0.5);
	m_shape.setPosition(t_position);
}

void Cell::mark(bool t_marked) // method that returns a bool for a marked cell
{
	m_marked = t_marked;

}

void Cell::addNeighbour(int t_cellID) // adding a cell id to the neighbours
{
	m_neighbours.push_back(t_cellID);
}

void Cell::setParentCell(int t_cell) // setting a parent cell 
{
	m_parentCellId = t_cell;
}

bool Cell::checkMark() // bool that is checking if the cell is marked
{
	return m_marked;
}

int Cell::returnID() // returning the id of a cell
{
	return m_id;
}

int Cell::returnParentCell() // returning the parent cell
{
	return m_parentCellId;
}

std::vector<int>& Cell::neighbours() // returning all the neighbours
{
	return m_neighbours;
}


void Cell::render(sf::RenderWindow& t_window) // rendering the cells on the screen
{
	t_window.draw(m_shape);
}

sf::RectangleShape Cell::getRect() // returning the cell rectangle shape
{
	return m_shape;
}
