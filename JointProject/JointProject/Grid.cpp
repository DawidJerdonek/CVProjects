#include "Grid.h"

Grid::Grid()
{
    initialiseMap();
}

Grid::~Grid()
{
}

Grid::Grid(int t_rows, int t_cols)
{

}

std::vector<int> Grid::breadthFirst(int t_startCellId, int t_destCellId)
{
    return std::vector<int>();
}

void Grid::neighbours(int t_row, int t_col, std::vector<Cell> &t_cells, int t_current)
{

    // Let's see if we can find the neighbours of row 4 and column 4:


    // List all neighbors:
    for (int direction = 0; direction < 9; direction++) {
        if (direction == 4) continue; // Skip 4, this is ourself.

        int n_row = t_row + ((direction % 3) - 1); // Neighbor row
        int n_col = t_col + ((direction / 3) - 1); // Neighbor column

        // Check the bounds:
        if (n_row >= 0 && n_row < m_maxRows && n_col >= 0 && n_col < m_maxCols) {

            // A valid neighbor:
            std::cout << "Neighbor: " << n_row << "," << n_col << " - "<< t_current <<std::endl;
            t_cells.at(t_current).addNeighbour(n_row+(n_col*10));
        }
    }
}

void Grid::reset()
{
}

void Grid::initialiseMap()
{

    sf::Vector2f cellPositions{ 0,0 };
    int count = 0;
    for (int index = 0; index < m_maxRows; index++)
    {

        for (int i = 0; i < m_maxCols; i++)
        {
            Cell cell(cellPositions, count);

            cellPositions.x += ScreenSize::s_width / 10; // adjusting cell position on screen - x axis
            if (cellPositions.x >= 1440)
            {
                cellPositions.x = 0;
                cellPositions.y += ScreenSize::s_height / 10; // adjusting cell position on screen - y axis
            }
            count++;
            m_cellsArray.push_back(cell);// pushing back the cell
        }
    }
    int p = 0;

    for (int i = 0; i < 100; i++)
    {
        int posY = i / 10;
        int posX = i % 10;
        neighbours(posX, posY, m_cellsArray, i);
    }
    m_cellsArray.size();
}

void Grid::update(double dt) // update method.... very much used
{
}

void Grid::render(sf::RenderWindow& t_window) // rendering the grid
{
    for (int index = 0; index < 100; index++)
    {
        m_cellsArray.at(index).render(t_window);
    }
}

Cell Grid::returnCell(int t_id) // returning the cell and its id
{
    return m_cellsArray.at(t_id);
}

std::vector<Cell> Grid::returnAllCells() // returning all the cells
{
    return m_cellsArray;
}



int Grid::breadthSearch(int startCellID, int DestCellID) // method for breadthFirstSearch
{
    bool reachDestination = false;
    std::queue<Cell> cellQueue;

    Cell Startcell = m_cellsArray.at(startCellID);
    cellQueue.emplace(Startcell);
    m_cellsArray.at(startCellID).mark(true);

    std::vector<Cell> myGrid = m_cellsArray;
    std::vector<int> idsToTraverse;
    int childCellID = 0;
    int currentCell = 0;
    int currentX = 0;
    int currentY = 0;

    int directionBFS = 0;

    for (int k = 0; k < 100; k++)
    {
        m_cellsArray.at(k).mark(false);

    }

    while (!cellQueue.empty() && reachDestination == false)
    {
        for (int index = 0; index < cellQueue.front().neighbours().size() && !reachDestination; index++)
        {
            Cell childCell(m_cellsArray.at(cellQueue.front().neighbours().at(index)));
            childCellID = childCell.returnID();

            std::cout << "Cell Queue Count: " << cellQueue.front().neighbours().size() << std::endl;

            //if we have found dest cell
            if (childCellID == DestCellID)
            {
                reachDestination = true;
                m_cellsArray.at(DestCellID).setParentCell(cellQueue.front().returnID());
            }
            else if (childCell.checkMark() == false)
            {
                m_cellsArray.at(childCell.returnID()).setParentCell(cellQueue.front().returnID());
                childCell.mark(true);
                cellQueue.push(childCell);
            }
        }
        cellQueue.pop();
    }
    return m_cellsArray.at(childCellID).returnParentCell();
}