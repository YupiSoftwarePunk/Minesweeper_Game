#include "../Cell/Cell.hpp"
#include "../Board/Board.hpp"
#include "../Player/Player.hpp"
#include "../Game/Game.hpp"



int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    Game game(10, 10, 50); 
    game.start();
    return 0;
}