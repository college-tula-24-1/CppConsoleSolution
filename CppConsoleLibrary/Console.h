#pragma once
#include "Types.h"
#include <conio.h>

class Console
{
	HANDLE descriptorOutput;
	HANDLE descriptorInput;

	std::string title;

	COORD GetCursorCoord();
public:
	Console(std::string title = "");

	HANDLE DescriptorOutput() const;
	HANDLE DescriptorInput() const;

	void Clear();

	void CursorPosition(Point);
	void CursorPosition(int, int);
	Point CursorPosition();
	int RowPosition();
	int ColumnPosition();

	void CursorSize(int);
	int CursorSize() const;

	void CursorVisible(bool = true);

	void Write(const char*);
	void Write(std::string);
	void Write(char);

	void WritePosition(Point, std::string);
	void WritePosition(Point, const char*);
	void WritePosition(Point, char);

	void ForeColor(Colors);
	Colors ForeColor();

	void BackColor(Colors);
	Colors BackColor();

	int GetChar();
	int KeyPressed();
};

