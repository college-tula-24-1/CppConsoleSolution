#include "RectangleView.h"

void RectangleView::BufferViewedInit()
{
	WORD attributes = (WORD)this->backColor << 4 | (WORD)this->foreColor;

	for (int i{}; i < this->size.width * this->size.height; i++)
	{
		this->bufferViewed[i].Char.AsciiChar = ' ';
		this->bufferViewed[i].Attributes = attributes;
	}
}

void RectangleView::BufferSavedInit()
{
	COORD bufferSize{ this->size.width, this->size.height };
	COORD bufferPosition{ 0, 0 };
	SMALL_RECT screenPosition{
		this->position.column,
		this->position.row,
		this->position.column + size.width,
		this->position.row + size.height };
	
	bool success = ReadConsoleOutputA(
		console->DescriptorOutput(),
		this->bufferSaved,
		bufferSize,
		bufferPosition,
		&screenPosition);
}

void RectangleView::Show()
{
	COORD bufferSize{ this->size.width, this->size.height };
	COORD bufferPosition{ 0, 0 };
	SMALL_RECT screenPosition{
		this->position.column,
		this->position.row,
		this->position.column + size.width,
		this->position.row + size.height };

	BufferSavedInit();
	BufferViewedInit();

	WriteConsoleOutputA(
		console->DescriptorOutput(),
		bufferViewed,
		bufferSize,
		bufferPosition,
		&screenPosition);
}

void RectangleView::Hide()
{
	COORD bufferSize{ this->size.width, this->size.height };
	COORD bufferPosition{ 0, 0 };
	SMALL_RECT screenPosition{
		this->position.column,
		this->position.row,
		this->position.column + size.width,
		this->position.row + size.height };

	WriteConsoleOutputA(
		console->DescriptorOutput(),
		bufferSaved,
		bufferSize,
		bufferPosition,
		&screenPosition);
}
