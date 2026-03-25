#include "Cell.h"

Cell::Cell(Point point)
	: point{ point },
	type{ CellType::Water },
	isShot{ false }{}

Cell::Cell(int row, int column)
	: Cell(Point{ row, column }){}

Cell::Cell() : Cell(Point{}){}

CellType& Cell::Type()
{
	return this->type;
}

bool& Cell::IsShot()
{
	return this->isShot;
}

