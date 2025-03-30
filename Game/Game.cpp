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
void Game::Start()
{
	while ((!gameOver_ && player_.getLives() > 0) || (!gameOver_ || player_.getLives() > 0))
	{
		PrintBoard();
		ActionInput();
		CheckGameStatus();
	}
}


// ��������� �����
void Game::PrintBoard()
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
			else if (cell.getIsMarked())
			{
				std::cout << cell.getNearbyBombs() << " ";
			}
		}
		std::cout << "\n";
	}
}



// ���� ��������� � ��������
void Game::ActionInput()
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
		bool hitBomb = board_.OpenCell(x, y);
		board_.CalculateNearbyBombs();

		if (hitBomb) 
		{
			player_.LoseLife();
			gameOver_ = true;
			std::cout << "�� ��������� �� ����! �������� ������: " << player_.getLives() << "\n";
		}
	}
	else if (action == 'M')
	{
		board_.MarkCell(x, y); 
	}
	else
	{
		::exit(-1);
		std::cout << "\n\n������� ������� ��������!!\n\n";
	}
}



// �������� �� �������
void Game::CheckGameStatus()
{
	if (board_.CheckWin()) 
	{
		std::cout << "������! ������� �������!\n";
		player_.LevelUp();
		gameOver_ = true;
	}
}
