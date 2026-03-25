#include "Field.h"

Field::Field()
{
	for (int row{}; row < size; row++)
	{
		std::vector<Cell*> line;
		for (int column{}; column < size; column++)
			line.push_back(new Cell(row, column));
		cells.push_back(line);
	}
}

Field::~Field()
{
	for (int row{}; row < size; row++)
	{
		for (int column{}; column < size; column++)
			delete cells[row][column];
		cells[row].clear();
	}
	cells.clear();
}

void Field::SetCellType(Point point, CellType type)
{
	cells[point.row][point.column]->Type() = type;
}

void Field::SetCellShot(Point point)
{
	cells[point.row][point.column]->IsShot() = true;
}

Cell* Field::GetCell(Point point)
{
	return cells[point.row][point.column];
}

void Field::SetShips(std::vector<Ship*> flotilla)
{
	for (auto ship : flotilla)
	{
		int row{ ship->Row() };
		int column{ ship->Column() };
		for (int s{}; s < ship->Size(); s++)
		{
			SetCellType(Point{ row, column });
			(ship->Direction() == DirectionShip::Horizontal) ? column++ : row++;
		}
	}
}

HitType Field::CheckShot(Point point)
{
	if (cells[point.row][point.column]->IsShot())
		return HitType::Beside;
	if (cells[point.row][point.column]->Type() == CellType::Water)
		return HitType::Beside;
	if (cells[point.row][point.column]->Type() == CellType::Deck)
		return HitType::Reach;
}
