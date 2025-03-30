#pragma once

class Cell
{


public:
    // �����������
    Cell() : isOpen_(false), hasBomb_(false), isMarked_(false), nearbyBombs_(0) {}

    // ������� � �������
    void setIsOpen(bool isOpen);
    void setHasBomb(bool value);
    void setIsMarked(bool isMarked);
    void setNearbyBombs(int count);


    bool getIsOpen() const;
    bool getHasBomb() const;
    bool getIsMarked() const;
    int getNearbyBombs() const;


    // ������� ������
    void Open();

    // �������� ������
    void Mark();



private:
    bool isOpen_;     
    bool hasBomb_;    
    bool isMarked_;   
    int nearbyBombs_; 
};

