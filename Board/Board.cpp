#include "Board.hpp"


// Сеттеры
void Board::setHeight(int height)
{
	this->height_ = height;
}

void Board::setWidth(int width)
{
	this->width_ = width;
}

void Board::setTotalMines(int mines)
{
	this->totalMines_ = mines;
}

void Board::setGrid(std::vector < std::vector<Cell>>& grid)
{
    this->grid_ = grid;
}



// Геттеры
int Board::getHeight()
{
	return height_;
}

int Board::getWidth()
{
	return width_;
}

int Board::getMines()
{
	return totalMines_;
}

const std::vector<std::vector<Cell>>& Board::getGrid() const
{
	return grid_;
}



// Размещение мин случайным образом
void Board::placeMines()
{
    srand(time(0));

    int placed = 0;
    while (placed < totalMines_) 
    {
        int posititon = rand() % (height_ * width_);
        int x = posititon / width_;
        int y = posititon % width_;

        if (!grid_[x][y].getHasBomb()) 
        {
            grid_[x][y].setHasBomb(true);
            placed++;
        }
    }
}


// Подсчет мин вокруг каждой ячейки
void Board::calculateNearbyBombs()
{
    for (int y = 0; y < height_; y++) 
    {
        for (int x = 0; x < width_; x++) 
        {
            if (grid_[y][x].getHasBomb())
            {
                continue;
            }

            int count = 0;

            for (int dy = -1; dy <= 1; dy++)
            {
                for (int dx = -1; dx <= 1; dx++)
                {
                    int ny = y + dy;
                    int nx = x + dx;

                    if (ny >= 0 && ny < height_ && nx >= 0 && nx < width_) 
                    {
                        if (grid_[ny][nx].getHasBomb())
                        {
                            count++;
                        }
                    }
                }
            }
            grid_[y][x].setNearbyBombs(count);
        }
    }
}



// Открытие ячейки и открытие пустых областей
bool Board::openCell(int x, int y)
{
    if (x < 0 || x >= width_ || y < 0 || y >= height_ || grid_[y][x].getIsOpen())
    {
        return false;
    }

    else if (grid_[y][x].getHasBomb()) 
    {
        return true; 
    }
    else
    {
        grid_[y][x].Open();

        if (grid_[y][x].getNearbyBombs() == 0 && !grid_[y][x].getHasBomb()) 
        {
            for (int dy = -1; dy <= 1; dy++)
            {
                for (int dx = -1; dx <= 1; dx++) 
                {
                    openCell(x + dx, y + dy);
                }
            }
        }

        return false;
    }
}

void Board::markCell(int x, int y)
{
    if (x >= 0 && x < width_ && y >= 0 && y < height_) 
    {
        grid_[y][x].Mark();
    }
}



// Проверка на победу (все безопасные ячейки открыты)
bool Board::checkWin() const
{
    for (const auto& row : grid_) 
    {
        for (const auto& cell : row) 
        {
            if (!cell.getHasBomb() && !cell.getIsOpen())
            {
                return false;
            }
        }
    }
    return true;
}

