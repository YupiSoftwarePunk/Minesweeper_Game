#pragma once

#include <vector>
#include <cstdlib> 
#include <ctime>
#include "../Cell/Cell.hpp"

class Board 
{
public:
    // конструктор
    Board(int height, int width, int mines) : height_(height), width_(width), totalMines_(mines)
    {
        grid_.resize(height_, std::vector<Cell>(width_));
        PlaceMines();
        CalculateNearbyBombs();
    }


    // Сеттеры
    void setHeight(int height);
    void setWidth(int width);
    void setTotalMines(int mines);
    void setGrid(std::vector < std::vector<Cell>>& grid);


    // Геттеры
    int getHeight();
    int getWidth();
    int getMines();
    const std::vector<std::vector<Cell>>& getGrid() const;


    // Размещение мин случайным образом
    void PlaceMines();


    // Подсчет мин вокруг каждой ячейки
    void CalculateNearbyBombs();


    // Открытие ячейки и открытие пустых областей
    bool OpenCell(int x, int y);


    // Пометка ячейки, что в ней есть бомба
    void MarkCell(int x, int y);


    // Проверка на победу (все безопасные ячейки открыты)
    bool CheckWin() const;


private:
    int height_;
    int width_;
    int totalMines_;
    std::vector<std::vector<Cell>> grid_;
};
