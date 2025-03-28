#include "Minesweeper.hpp"

const unsigned int SIZE = 1e2 - 1;



void empty(char gh[SIZE][SIZE], char fakem[SIZE][SIZE], int i, int j)
{
    if (gh[i][j] != 'X' && fakem[i][j] == char(220)) // 1
    {
        fakem[i][j] = gh[i][j];
        if (gh[i][j] == '0')
        {
            empty(gh, fakem, i, j - 1);
            empty(gh, fakem, i, j + 1);
            empty(gh, fakem, i - 1, j - 1);
            empty(gh, fakem, i + 1, j - 1);
            empty(gh, fakem, i + 1, j + 1);
            empty(gh, fakem, i - 1, j + 1);
            empty(gh, fakem, i - 1, j);
            empty(gh, fakem, i + 1, j);
        }
    }
}


void fill(char l[SIZE][SIZE], int k)
{
    int c = 1;

    while (c <= k)
    {
        int ibomb = 1 + (rand() % 9);
        int jbomb = 1 + (rand() % 9);

        if (l[ibomb][jbomb] == '0')
        {
            l[ibomb][jbomb] = 'X';
            std::cout << ibomb << "  " << jbomb << std::endl;
            ++l[ibomb - 1][jbomb];
            ++l[ibomb + 1][jbomb]; // vertical

            ++l[ibomb + 1][jbomb + 1];
            ++l[ibomb - 1][jbomb - 1]; // diagonal NW

            ++l[ibomb - 1][jbomb + 1];
            ++l[ibomb + 1][jbomb - 1]; // diagonal NE

            ++l[ibomb][jbomb - 1];
            ++l[ibomb][jbomb + 1]; // horizontal
            c++;
        }
    }
    for (int i = 1; i <= 9; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            std::cout << l[i][j] << " ";
            if (j >= 9)
            {
                std::cout << std::endl;
            }
        }
    }
}


void fakematrix(char s[SIZE][SIZE])
{
    for (int i = 1; i <= 9; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            s[i][j] = char(220);
        }
    }
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            std::cout << s[i][j] << " ";
            if (j >= 9)
            {
                std::cout << std::endl;
            }
        }
    }
}


void prints(char q[SIZE][SIZE])
{
    for (int i = 1; i <= 9; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            std::cout << q[i][j] << " ";

            if (j >= 9)
            {
                std::cout << std::endl;
            }
        }
    }
}


int main()
{
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


    fill(a, bombs);
    std::cout << std::endl;
    fakematrix(p);
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
            prints(p);
            c++;
        }
        if (a[x][y] == 'X')
        {
            p[x][y] = a[x][y];
            std::cout << "Oops! You lose. Would you like to play again? If yes press Y" << std::endl;
            prints(p);

            return 0;
        }
        if (a[x][y] == '0')
        {
            empty(a, p, x, y);
            prints(p);
        }
        if (c == 72)
        {
            std::cout << "WIN" << std::endl;
        }
    }
}