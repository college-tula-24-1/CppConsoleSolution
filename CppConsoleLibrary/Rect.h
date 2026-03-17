#pragma once
#include "Types.h"


class Rect
{
	Point position;
	Size size;
	Colors backColor;
	Colors foreColor;
public:
	// 1
	Rect(Point position,
		Size size,
		Colors backColor,
		Colors foreColor);

	// 2
	Rect(int row,
		int column,
		Size size,
		Colors backColor,
		Colors foreColor);

	// 3
	Rect(Point position,
		int width,
		int height,
		Colors backColor,
		Colors foreColor);

	// 4
	Rect(int row,
		int column,
		int width,
		int height,
		Colors backColor,
		Colors foreColor);

	// 5
	Rect(Point position, Size size);

	// 6
	Rect(int row, int column, Size size);

	// 7
	Rect(Point position,
		int width,
		int height);

	// 8
	Rect(int row,
		int column,
		int width,
		int height);

	// 9
	Rect(Point position);

	// 10
	Rect(int row, int column);

	// 11
	Rect();


	Point GetPosition() const;
	int Row() const;
	int Column() const;

	Size GetSize() const;
	int Width() const;
	int Height() const;

	Colors BackColor() const;
	void BackColor(Colors backColor);

	Colors ForeColor() const;
	void ForeColor(Colors foreColor);

	void Move(Point position);
	void Move(int row, int column);

	void Resize(Size size);
	void Resize(int width, int height);


};




