#include "Game.hpp"

// �������
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



// �������
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



// ������ ��������� �����, ����� ��������� � ��������, �������� �� �������
void Game::start()
{
	while ((!gameOver_ && player_.getLives() > 0) || (!gameOver_ || player_.getLives() > 0))
	{
		printBoard();
		handleInput();
		checkGameState();
	}
}


// ��������� �����
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



// ���� ��������� � ��������
void Game::handleInput()
{
	int x, y;
	char action;

	std::cout << "������� �������� (O - �������, M - ��������): ";
	std::cin >> action;

	std::cout << "������� ���������� x: ";
	std::cin >> x;

	std::cout << "������� ���������� y: ";
	std::cin >> y;


	if (action == 'O') 
	{
		bool hitBomb = board_.openCell(x, y);
		board_.calculateNearbyBombs();

		if (hitBomb) 
		{
			player_.loseLife();
			gameOver_ = true;
			std::cout << "�� ��������� �� ����! �������� ������: " << player_.getLives() << "\n";
		}
	}
	else if (action == 'M')
	{
		board_.markCell(x, y); 
	}
	else
	{
		::exit(-1);
		std::cout << "\n\n������� ������� ��������!!\n\n";
	}
}



// �������� �� �������
void Game::checkGameState()
{
	if (board_.checkWin()) 
	{
		std::cout << "������! ������� �������!\n";
		player_.levelUp();
		gameOver_ = true;
	}
}
