#pragma once

#include <vector>
#include <random>
#include "../Cell/Cell.hpp"

class Board 
{
public:
    // �����������
    Board(int height, int width, int mines) : height_(height), width_(width), totalMines_(mines)
    {
        grid_.resize(height_, std::vector<Cell>(width_));
        placeMines();
        calculateNearbyBombs();
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
    void placeMines();


    // ������� ��� ������ ������ ������
    void calculateNearbyBombs();


    // �������� ������ � �������� ������ ��������
    bool openCell(int x, int y);


    // ������� ������, ��� � ��� ���� �����
    void markCell(int x, int y);


    // �������� �� ������ (��� ���������� ������ �������)
    bool checkWin() const;


private:
    int height_;
    int width_;
    int totalMines_;
    std::vector<std::vector<Cell>> grid_;
};
