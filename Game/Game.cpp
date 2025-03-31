#include "Game.hpp"

// сеттеры
void Game::setBoard(Board board)
{
	this->board_ = board;
}

void Game::setPlayer(Player player)
{
	this->player_ = player;
}

void Game::setGameOver(bool gameOver)
{
	this->gameOver_ = gameOver;
}



// геттеры
Board Game::getBoard()
{
	return board_;
}

Player Game::getPlayer()
{
	return player_;
}

bool Game::getGameOver()
{
	return gameOver_;
}



// Запуск отрисовки сетки, ввода координат и действия, проверка на выигрыш
void Game::Start()
{
	while ((!gameOver_ && player_.getLives() > 0) || (!gameOver_ || player_.getLives() > 0))
	{
		PrintBoard();
		ActionInput();
		CheckGameStatus();
	}
}


// отрисовка сетки
void Game::PrintBoard()
{
	const auto& grid = board_.getGrid();


	std::cout << "   ";
	for (int x = 0; x < grid[0].size(); x++) 
	{
		std::cout << x + 1 << " ";
	}
	std::cout << "\n";



	for (int y = 0; y < grid.size(); y++) 
	{
		std::cout << y + 1 << " |";  

		for (int x = 0; x < grid[y].size(); x++) 
		{
			const auto& cell = grid[y][x];
		
			if (cell.getIsMarked())
			{
				std::cout << "M ";
			}
			else if (!cell.getIsOpen()) 
			{ 
				std::cout << "# ";
			}
			else if (cell.getIsOpen())
			{
				std::cout << cell.getNearbyBombs() << " ";
			}
			else if (cell.getHasBomb())
			{
				std::cout << "* ";
			}
			else if (cell.getIsMarked())
			{
				std::cout << cell.getNearbyBombs() << " ";
			}
		}
		std::cout << "\n";
	}
}



// ввод координат и действия
void Game::ActionInput()
{
	int x, y;
	char action;

	std::cout << "Введите действие (O - открыть, M - пометить): ";
	std::cin >> action;

	std::cout << "Введите координату x: ";
	std::cin >> x;
	x--;

	std::cout << "Введите координату y: ";
	std::cin >> y;
	y--;


	if (action == 'O') 
	{
		bool hitBomb = board_.OpenCell(x, y);
		board_.CalculateNearbyBombs();

		if (hitBomb) 
		{
			player_.LoseLife();
			gameOver_ = true;
			std::cout << "Вы наступили на мину! Осталось жизней: " << player_.getLives() << "\n";
		}
	}
	else if (action == 'M')
	{
		board_.MarkCell(x, y); 
	}
	else
	{
		::exit(-1);
		std::cout << "\n\nНеверно введено действие!!\n\n";
	}
}



// проверка на выигрыш
void Game::CheckGameStatus()
{
	if (board_.CheckWin()) 
	{
		std::cout << "Победа! Уровень пройден!\n";
		player_.LevelUp();
		gameOver_ = true;
	}
}
