#include "Ship.h"

Ship::Ship(Point start, int size, DirectionShip direction)
	: start{ start },
	size{ size },
	direction{ direction },
	damage{}{}

Ship::Ship(int row, int column, int size, DirectionShip direction)
	: Ship(Point{ row, column }, size, direction){}

Point& Ship::Start()
{
	return start;
}

int& Ship::Row()
{
	return start.row;
}

int& Ship::Column()
{
	return start.column;
}

int Ship::Size() const
{
	return size;
}

DirectionShip& Ship::Direction()
{
	return direction;
}

int& Ship::Damage()
{
	return damage;
}

bool Ship::IsDeed()
{
	return damage == size;
}

bool Ship::IsPoint(Point point)
{
	int row{ start.row };
	int column{ start.column };

	for (int s{}; s < size; s++)
	{
		if (point.row == row && point.column == column)
			return true;
		(direction == DirectionShip::Horizontal) ? column++ : row++;
	}

	return false;
}
