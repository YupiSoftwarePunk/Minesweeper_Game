#pragma once

#include <Windows.h>
#include <iostream>
#include "../Board/Board.hpp"
#include "../Player/Player.hpp"

class Game 
{


public:
    // конструктор
    Game(int width, int height, int mines) : board_(height, width, mines), player_(3), gameOver_(false) {}


    // сеттеры
    void setBoard(Board board);
    void setPlayer(Player player);
    void setGameOver(bool gameOver);


    // геттеры
    Board getBoard();
    Player getPlayer();
    bool getGameOver();


    // Запуск отрисовки сетки, ввода координат и действия, проверка на выигрыш
    void Start();


    // отрисовка сетки
    void PrintBoard();


    // ввод координат и действия
    void ActionInput();


    // проверка на выигрыш
    void CheckGameStatus();


private:
    Board board_;
    Player player_;
    bool gameOver_;
};
