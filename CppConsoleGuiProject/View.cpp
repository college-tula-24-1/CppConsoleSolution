#include "View.h"

Console* View::console = new Console();

void View::BufferViewedInit()
{
	WORD attributes = (WORD)this->backColor << 4 | (WORD)this->foreColor;

	for (int i{}; i < this->size.width * this->size.height; i++)
	{
		this->bufferViewed[i].Char.AsciiChar = ' ';
		this->bufferViewed[i].Attributes = attributes;
	}
}

void View::BufferSavedInit()
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

View::View(Position position, 
	Size size,
	Colors backColor, 
	Colors foreColor)
	: position { position },
	size{ size },
	backColor{ backColor },
	foreColor{ foreColor }
{
	bufferViewed = new CHAR_INFO[size.width * size.height];
	bufferSaved = new CHAR_INFO[size.width * size.height];
}

View::View(Position position, Size size)
	: View(position, size, Colors::Black, Colors::White){}

View::View()
	: View(Position{}, Size{}){}

View::~View()
{
	delete[] bufferViewed;
	delete[] bufferSaved;
}


Console* View::GetConsole()
{
	return console;
}


Position View::GetPosition() const
{
	return this->position;
}
int View::Row() const
{
	return this->position.row;
}
int View::Column() const
{
	return this->position.column;
}
Size View::GetSize() const
{
	return this->size;
}
int View::Width() const
{
	return this->size.width;
}
int View::Height() const
{
	return this->size.height;
}
Colors View::BackColor() const
{
	return this->backColor;
}
void View::BackColor(Colors backColor)
{
	this->backColor = backColor;
}

Colors View::ForeColor() const
{
	return this->foreColor;
}

void View::ForeColor(Colors foreColor)
{
	this->foreColor = foreColor;
}

bool View::IsVisible() const
{
	return this->isVisible;
}

void View::Move(Position position)
{
	if (isVisible)
		this->Hide();
	
	this->position = position;

	this->BufferSavedInit();

	if (isVisible)
		this->Show();

}

void View::Move(int row, int column)
{
	this->Move(Position{ row, column });
}

void View::Resize(Size size)
{
	if (isVisible)
		this->Hide();

	this->size = size;

	BufferSavedInit();
	BufferViewedInit();

	if (isVisible)
		this->Show();
}

void View::Resize(int width, int height)
{
	this->Resize(Size{ width, height });
}

void View::Show()
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

void View::Hide()
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


