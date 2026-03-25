#include "Window.h"

void Window::BufferViewedInit()
{
	View::BufferViewedInit();

	if(this->style == BorderStyle::None)
		return;

	int* border = (this->style == BorderStyle::Single) ? Border().Single : Border().Double;

	int index{};
	bufferViewed[index++].Char.AsciiChar = border[(int)BorderIndex::TopLeft];
	for(; index < size.width - 1; index++)
		bufferViewed[index].Char.AsciiChar = border[(int)BorderIndex::Horizontal];
	bufferViewed[index++].Char.AsciiChar = border[(int)BorderIndex::TopRight];

	for (int row{ 1 }; row < size.height - 1; row++)
	{
		bufferViewed[index].Char.AsciiChar = border[(int)BorderIndex::Vertical];
		index += size.width - 1;
		bufferViewed[index++].Char.AsciiChar = border[(int)BorderIndex::Vertical];
	}

	bufferViewed[index++].Char.AsciiChar = border[(int)BorderIndex::BottomLeft];
	for (int i{ 1 }; i < size.width - 1; i++)
		bufferViewed[index++].Char.AsciiChar = border[(int)BorderIndex::Horizontal];
	bufferViewed[index].Char.AsciiChar = border[(int)BorderIndex::BottomRight];

	// title
	if (this->title.length() > 0)
	{
		int column{ (size.width - (int)title.length() - 2) / 2 };
		bufferViewed[column++].Char.AsciiChar = ' ';
		for(int tc : this->title)
			bufferViewed[column++].Char.AsciiChar = tc;
		bufferViewed[column].Char.AsciiChar = ' ';
	}
}

Window::Window(Position position, 
	Size size, 
	Colors backColor, 
	Colors foreColor, 
	std::string title, 
	BorderStyle style)
	: View(position, size, backColor, foreColor),
	title{ title },
	style{ style }{}
