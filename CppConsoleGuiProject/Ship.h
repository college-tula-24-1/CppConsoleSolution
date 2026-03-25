#pragma once

#include "Cell.h"

enum class DirectionShip
{
	Horizontal,
	Vertical
};

class Ship
{
	Point start;
	DirectionShip direction;
	int size;
	int damage;
public:
	Ship(Point start, int size, DirectionShip direction);
	Ship(int row, int column, int size, DirectionShip direction);

	Point& Start();
	int& Row();
	int& Column();

	int Size() const;
	DirectionShip& Direction();
	int& Damage();

	bool IsDeed();
	bool IsPoint(Point point);
};

