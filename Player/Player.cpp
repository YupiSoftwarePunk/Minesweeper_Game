#include "Player.hpp"

// �������
void Player::setLives(int lives)
{
	this->lives_ = lives;
}

void Player::setLevel(int level)
{
	this->level_ = level;
}



// �������
int Player::getLives()
{
	return lives_;
}

int Player::getLevel()
{
	return level_;
}



// ��������� ������ ������
void Player::levelUp()
{
	level_++;
}


// ���������� ������ ������
void Player::loseLife()
{
	if (lives_ > 0)
	{
		lives_--;
	}
}
