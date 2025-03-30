#pragma once


class Player
{


public:
    // конструктор
    Player(int lives) : lives_(lives), level_(1) {}

    // Сеттеры
    void setLives(int lives);
    void setLevel(int level);


    // Геттеры
    int getLives();
    int getLevel();



    // повышение уровня игрока
    void LevelUp();


    // уменьшение жизней игрока
    void LoseLife();

private:
    int lives_;
    int level_;
};