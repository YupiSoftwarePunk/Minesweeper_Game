#pragma once


class Player
{


public:
    // �����������
    Player(int lives) : lives_(lives), level_(1) {}

    // �������
    void setLives(int lives);
    void setLevel(int level);


    // �������
    int getLives();
    int getLevel();



    // ��������� ������ ������
    void LevelUp();


    // ���������� ������ ������
    void LoseLife();

private:
    int lives_;
    int level_;
};