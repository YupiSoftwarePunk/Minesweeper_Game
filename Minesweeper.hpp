#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Minesweeper.cpp"


class Minesweeper
{
public:
	void empty(char gh[SIZE][SIZE], char fakem[SIZE][SIZE], int i, int j);


	void fill(char l[SIZE][SIZE], int k);


	void fakematrix(char s[SIZE][SIZE]);

	void prints(char q[SIZE][SIZE]);
};

