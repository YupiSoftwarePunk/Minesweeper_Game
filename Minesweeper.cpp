#include "Minesweeper.hpp"

const unsigned SIZE = 1e2 - 1;



void Minesweeper::empty(char gh[SIZE][SIZE], char fakem[SIZE][SIZE], int i, int j)
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


void Minesweeper::fill(char l[SIZE][SIZE], int k)
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


void Minesweeper::fakematrix(char s[SIZE][SIZE])
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


void Minesweeper::prints(char q[SIZE][SIZE])
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
