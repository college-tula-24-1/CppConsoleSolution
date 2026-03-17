#include "Console.h"

COORD Console::GetCursorCoord()
{
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(this->descriptorOutput, &consoleInfo);
	COORD coord{ consoleInfo.dwCursorPosition };

	return coord;
}

Console::Console(std::string title)
	: title{ title },
	descriptorOutput{ GetStdHandle(STD_OUTPUT_HANDLE) },
	descriptorInput{ GetStdHandle(STD_INPUT_HANDLE) }
{
	SetConsoleTitleA(this->title.c_str());
}

HANDLE Console::DescriptorOutput() const
{
	return this->descriptorOutput;
}

HANDLE Console::DescriptorInput() const
{
	return this->descriptorInput;
}

void Console::Clear()
{
	system("cls");
}

void Console::CursorPosition(Point position)
{
	COORD coord{ position.column, position.row };
	SetConsoleCursorPosition(this->descriptorOutput, coord);
}

void Console::CursorPosition(int row, int column)
{
	this->CursorPosition(Point{ row, column });
}

Point Console::CursorPosition()
{
	COORD coord{ GetCursorCoord() };
	return Point{ coord.Y, coord.X };
}

int Console::RowPosition()
{
	return GetCursorCoord().Y;
}

int Console::ColumnPosition()
{
	return GetCursorCoord().X;
}

void Console::CursorSize(int size)
{
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = size;
	SetConsoleCursorInfo(this->descriptorOutput, &cursorInfo);
}

int Console::CursorSize() const
{
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(this->descriptorOutput, &cursorInfo);

	return cursorInfo.dwSize;
}

void Console::CursorVisible(bool visible)
{
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.bVisible = visible;
	SetConsoleCursorInfo(this->descriptorOutput, &cursorInfo);
}

void Console::Write(const char* message)
{
	LPDWORD written{};
	WriteConsoleA(
		this->descriptorOutput,
		message,
		strlen(message),
		written,
		nullptr);
}

void Console::Write(std::string message)
{
	this->Write(message.c_str());
}

void Console::Write(char symbol)
{
	this->Write(std::string(1, symbol));
}

void Console::WritePosition(Point position, std::string message)
{
	this->WritePosition(position, message.c_str());
}

void Console::WritePosition(Point position, const char* message)
{
	this->CursorPosition(position);
	this->Write(message);
}

void Console::WritePosition(Point position, char symbol)
{
	this->WritePosition(position, std::string(1, symbol));
}

void Console::ForeColor(Colors color)
{
	int backColor{ (int)this->BackColor() << 4 };
	SetConsoleTextAttribute(this->descriptorOutput, backColor | (int)color);
}

Colors Console::ForeColor()
{
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(this->descriptorOutput, &consoleInfo);

	Colors foreColor{ (Colors)(consoleInfo.wAttributes & 0b1111) };
	return foreColor;
}

void Console::BackColor(Colors color)
{
	int foreColor{ (int)this->ForeColor() };
	SetConsoleTextAttribute(this->descriptorOutput, foreColor | ((int)color << 4));
}

Colors Console::BackColor()
{
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(this->descriptorOutput, &consoleInfo);

	Colors backColor = { (Colors)((consoleInfo.wAttributes & (0b1111 << 4)) >> 4) };
	return backColor;
}


