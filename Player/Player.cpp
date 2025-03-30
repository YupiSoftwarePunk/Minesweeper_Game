#include "Player.hpp"

// Сеттеры
void Player::setLives(int lives)
{
	this->lives_ = lives;
}

void Player::setLevel(int level)
{
	this->level_ = level;
}



// Геттеры
int Player::getLives()
{
	return lives_;
}

int Player::getLevel()
{
	return level_;
}



// повышение уровня игрока
void Player::LevelUp()
{
	level_++;
}


// уменьшение жизней игрока
void Player::LoseLife()
{
	if (lives_ > 0)
	{
		lives_--;
	}
}
