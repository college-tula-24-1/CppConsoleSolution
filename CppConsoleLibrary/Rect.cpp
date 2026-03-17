#include "Rect.h"

// 1
Rect::Rect(Point position, 
	Size size, 
	Colors backColor, 
	Colors foreColor)
	: position{ position },
	size{ size },
	backColor{ backColor },
	foreColor{ foreColor }{}

// 2
Rect::Rect(int row, 
	int column, 
	Size size, 
	Colors backColor, 
	Colors foreColor)
	: Rect(Point{ row, column },
		size,
		backColor,
		foreColor){}
// 3
Rect::Rect(Point position,
	int width, 
	int height, 
	Colors backColor, 
	Colors foreColor)
	: Rect(position,
		Size{ width, height },
		backColor,
		foreColor) {}

// 4
Rect::Rect(int row, 
	int column, 
	int width, 
	int height, 
	Colors backColor, 
	Colors foreColor)
	: Rect(Point{ row, column },
		Size{ width, height },
		backColor,
		foreColor) {}

// 5
Rect::Rect(Point position, Size size)
	: Rect(position, 
		size,
		Colors::Black,
		Colors::White){}

// 6
Rect::Rect(int row, int column, Size size)
	: Rect(Point{ row, column }, size){}

// 7
Rect::Rect(Point position,
	int width, 
	int height)
	: Rect(position, Size{ width, height }) {}

// 8
Rect::Rect(int row, 
	int column, 
	int width, 
	int height)
	: Rect(Point(row, column), 
		Size{ width, height }) {}

// 9
Rect::Rect(Point position)
	: Rect(position, Size{}) {}

// 10
Rect::Rect(int row, int column)
	: Rect(Point(row, column)) {}

// 11
Rect::Rect() : Rect(0, 0) {}


Point Rect::GetPosition() const
{
	return this->position;
}
int Rect::Row() const
{
	return this->position.row;
}
int Rect::Column() const
{
	return this->position.column;
}
Size Rect::GetSize() const
{
	return this->size;
}
int Rect::Width() const
{
	return this->size.width;
}
int Rect::Height() const
{
	return this->size.height;
}
Colors Rect::BackColor() const
{
	return this->backColor;
}
void Rect::BackColor(Colors backColor)
{
	this->backColor = backColor;
}

Colors Rect::ForeColor() const
{
	return this->foreColor;
}

void Rect::ForeColor(Colors foreColor)
{
	this->foreColor = foreColor;
}

void Rect::Move(Point position)
{
	this->position = position;
}

void Rect::Move(int row, int column)
{
	this->Move(Point{ row, column });
}

void Rect::Resize(Size size)
{
	this->size = size;
}

void Rect::Resize(int width, int height)
{
	this->Resize(Size{ width, height });
}



