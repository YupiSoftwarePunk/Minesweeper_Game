#include "../Cell/Cell.hpp"
#include "../Board/Board.hpp"
#include "../Player/Player.hpp"
#include "../Game/Game.hpp"



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    std::cout << "\t\t\tДобро подаловать в игру Сапер!!\n\n";

    Game game(10, 10, 5); 
    game.Start();
    return 0;
}