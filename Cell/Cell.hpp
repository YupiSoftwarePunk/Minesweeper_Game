#pragma once

class Cell
{


public:
    // конструктор
    Cell() : isOpen_(false), hasBomb_(false), isMarked_(false), nearbyBombs_(0) {}

    // Сеттеры и геттеры
    void setIsOpen(bool isOpen);
    void setHasBomb(bool value);
    void setIsMarked(bool isMarked);
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

