#pragma once

#include <Windows.h>
#include <string>
#include <conio.h>

#include "Types.h"

class Console
{
protected:
	HANDLE descriptorOutput;
	HANDLE descriptorInput;

	std::string title;

	COORD GetCursorCoord();
public:
	Console(std::string title = "");

	HANDLE DescriptorOutput();
	HANDLE DescriptorInput();

	void CosoleWindowSize(int width, int height);

	void Clear();

	void CursorPosition(Position);
	void CursorPosition(int, int);
	Position CursorPosition();
	int RowPosition();
	int ColumnPosition();

	void CursorSize(int);
	int CursorSize() const;

	void CursorVisible(bool = true);

	void Write(const char*);
	void Write(std::string);
	void Write(char);

	void WritePosition(Position, std::string);
	void WritePosition(Position, const char*);
	void WritePosition(Position, char);

	void ForeColor(Colors);
	Colors ForeColor();

	void BackColor(Colors);
	Colors BackColor();

	int GetChar();
	int KeyPressed(); 
};

