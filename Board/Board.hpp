#pragma once

#include <vector>
#include <cstdlib> 
#include <ctime>
#include "../Cell/Cell.hpp"

class Board 
{
public:
    // �����������
    Board(int height, int width, int mines) : height_(height), width_(width), totalMines_(mines)
    {
        grid_.resize(height_, std::vector<Cell>(width_));
        PlaceMines();
        CalculateNearbyBombs();
    }


    // �������
    void setHeight(int height);
    void setWidth(int width);
    void setTotalMines(int mines);
    void setGrid(std::vector < std::vector<Cell>>& grid);


    // �������
    int getHeight();
    int getWidth();
    int getMines();
    const std::vector<std::vector<Cell>>& getGrid() const;


    // ���������� ��� ��������� �������
    void PlaceMines();


    // ������� ��� ������ ������ ������
    void CalculateNearbyBombs();


    // �������� ������ � �������� ������ ��������
    bool OpenCell(int x, int y);


    // ������� ������, ��� � ��� ���� �����
    void MarkCell(int x, int y);


    // �������� �� ������ (��� ���������� ������ �������)
    bool CheckWin() const;


private:
    int height_;
    int width_;
    int totalMines_;
    std::vector<std::vector<Cell>> grid_;
};
