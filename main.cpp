#include "Minesweeper.hpp"


int main()
{

    Minesweeper b;

    int bombs;
    srand(time(0));
    int x, y;
    char a[SIZE][SIZE];
    char ask;
    char p[SIZE][SIZE];
    int c = 1;


    for (int i = 1; i <= 9; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            a[i][j] = '0'; // ghost
        }
    }


    std::cout << "                  Choose the number of bombs that you want: ";
    std::cin >> bombs;


    b.fill(a, bombs);
    std::cout << std::endl;
    b.fakematrix(p);
    std::cout << std::endl;

    while (c < SIZE)
    {
        std::cout << std::endl;
        std::cout << "Enter the x and y: ";
        std::cin >> x >> y;

        if (x > 9 || y > 9)
        {
            std::cout << "Invalid move try again" << std::endl;
        }
        if (a[x][y] != 'X' && a[x][y] != '0')
        {
            p[x][y] = a[x][y];
            std::cout << std::endl;
            b.prints(p);
            c++;
        }
        else if (a[x][y] == 'X')
        {
            p[x][y] = a[x][y];
            std::cout << "Oops! You lose. Would you like to play again? If yes press Y" << std::endl;
            b.prints(p);

            return 0;
        }
        else if (a[x][y] == '0')
        {
            b.empty(a, p, x, y);
            b.prints(p);
        }
        else if (c == 72)
        {
            std::cout << "WIN" << std::endl;
        }
    }
}