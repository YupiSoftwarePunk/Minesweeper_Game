#include "Cell.hpp"


// �������

void Cell::setIsOpen(bool isOpen)
{
	this->isOpen_ = isOpen;
}

void Cell::setHasBomb(bool value)
{
	this->hasBomb_ = value;
}

void Cell::setIsMarked(bool isMarked)
{
	this->isMarked_ = isMarked;
}

void Cell::setNearbyBombs(int count)
{
	this->nearbyBombs_ = count;
}


// �������
bool Cell::getIsOpen() const
{
	return isOpen_;
}

bool Cell::getHasBomb() const
{
	return hasBomb_;
}

bool Cell::getIsMarked() const
{
	return isMarked_;
}

int Cell::getNearbyBombs() const
{
	return nearbyBombs_;
}


// ������� ������
void Cell::Open()
{
	if (!isMarked_)
	{
		isOpen_ = true;
	}
}


// �������� ������
void Cell::Mark()
{
	if (!isOpen_)
	{
		isMarked_ = !isMarked_;
	}
}
