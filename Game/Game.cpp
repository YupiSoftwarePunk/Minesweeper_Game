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
void Game::start()
{
	while ((!gameOver_ && player_.getLives() > 0) || (!gameOver_ || player_.getLives() > 0))
	{
		printBoard();
		handleInput();
		checkGameState();
	}
}


// отрисовка сетки
void Game::printBoard()
{
	const auto& grid = board_.getGrid();

	for (const auto& row : grid) 
	{
		for (const auto& cell : row) 
		{
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
				std::cout << "_ ";
			}
			else if (cell.getHasBomb())
			{
				std::cout << "* ";
			}
			else
			{
				std::cout << cell.getNearbyBombs() << " ";
			}
		}
		std::cout << "\n";
	}
}



// ввод координат и действия
void Game::handleInput()
{
	int x, y;
	char action;

	std::cout << "Введите действие (O - открыть, M - пометить): ";
	std::cin >> action;

	std::cout << "Введите координату x: ";
	std::cin >> x;

	std::cout << "Введите координату y: ";
	std::cin >> y;


	if (action == 'O') 
	{
		bool hitBomb = board_.openCell(x, y);
		board_.calculateNearbyBombs();

		if (hitBomb) 
		{
			player_.loseLife();
			gameOver_ = true;
			std::cout << "Вы наступили на мину! Осталось жизней: " << player_.getLives() << "\n";
		}
	}
	else if (action == 'M')
	{
		board_.markCell(x, y); 
	}
	else
	{
		::exit(-1);
		std::cout << "\n\nНеверно введено действие!!\n\n";
	}
}



// проверка на выигрыш
void Game::checkGameState()
{
	if (board_.checkWin()) 
	{
		std::cout << "Победа! Уровень пройден!\n";
		player_.levelUp();
		gameOver_ = true;
	}
}
