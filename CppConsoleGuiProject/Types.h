#pragma once

struct Position
{
	int row;
	int column;
};

struct Size
{
	int width;
	int height;
};

enum class Colors
{
	Black,
	DarkBlue,
	DarkGreen,
	DarkCyan,
	DarkRed,
	DarkMagenta,
	DarkYellow,
	Gray,
	DarkGray,
	Blue,
	Green,
	Cyan,
	Red,
	Magenta,
	Yellow,
	White
};

enum class BorderStyle
{
	None,
	Single,
	Double
};

struct Border
{
	int Single[11]{ 218, 194, 191, 195, 197, 180, 192, 193, 217, 196, 179 };
	int Double[11]{ 201, 203, 187, 204, 206, 185, 200, 202, 188, 205, 186 };
};

enum class BorderIndex
{
	TopLeft,
	TopCenter,
	TopRight,
	MiddleLeft,
	MiddleCenter,
	MiddleRight,
	BottomLeft,
	BottomCenter,
	BottomRight,
	Horizontal,
	Vertical,
	Cross = 4
};

