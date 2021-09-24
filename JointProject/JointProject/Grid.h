#pragma once
#include <iostream>
#include <vector>
#include "Cell.h"
#include "ScreenSize.h"
#include "Enemy.h"
#include <queue>

class Grid {
public:
	Grid();
	~Grid();

	Grid(int t_rows, int t_cols);

	std::vector<int> breadthFirst(int t_startCellId, int t_destCellId);

	void neighbours(int t_row, int t_col, std::vector<Cell>& t_cells, int t_current);
	void reset();
	void initialiseMap();
	void update(double dt);
	void render(sf::RenderWindow& t_window);
	Cell returnCell(int t_id);
	std::vector<Cell> returnAllCells();
	int breadthSearch( int startCellID, int DestCellID);

protected:

	//std::vector<std::vector<Cell>> m_cellsVectorArray;
	std::vector<Cell> m_cellsArray;

	int m_maxRows = 10;
	int m_maxCols = 10;
	int m_currentRow;
	int m_currentCol;


	//std::vector<Cell> m_cells;
};