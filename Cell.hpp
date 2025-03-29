#pragma once

class Cell
{
public:
    Cell() : isOpen_(false), hasBomb_(false), isMarked_(false), nearbyBombs_(0) {}

    // Сеттеры и геттеры
    void setHasBomb(bool value);
    void setNearbyBombs(int count);


    bool getIsOpen() const;
    bool getHasBomb() const;
    bool getIsMarked() const;
    int getNearbyBombs() const;


    // Открыть ячейку
    void Open();

    // Пометить ячейку
    void Mark();



private:
    bool isOpen_;     
    bool hasBomb_;    
    bool isMarked_;   
    int nearbyBombs_; 
};

