#include "GameViewLibrary.h"

GameView::GameView(int cellSize)
	: Window(), cellSize{cellSize}
{
	this->title = "Game Sea Battle";
	this->style = BorderStyle::Double;

	this->position = Position{ 2, 4 };
	
	int fieldCellsCount{ 12 };
	int widthScale{ 2 };
	int margin{ 2 };

	int width{ ((cellSize * fieldCellsCount) * 2 + margin * cellSize * 3) * widthScale };
	int height{ cellSize * fieldCellsCount + margin * cellSize * 2 };

	this->size = Size{ width, height };
	this->backColor = Colors::Gray;
	this->foreColor = Colors::Black;

	this->bufferViewed = new CHAR_INFO[size.width * size.height];
	this->bufferSaved = new CHAR_INFO[size.width * size.height];

	this->console->CosoleWindowSize(width, height);

}

FieldView::FieldView(Position position,
	int cellSize, 
	std::string title)
	: Window(), cellSize{ cellSize }
{
	this->title = title;
	this->style = BorderStyle::Double;

	this->position = position;

	int cellsCount{ 12 };
	int widthScale{ 2 };
	int margin{ 2 };

	int width{ cellSize * cellsCount * widthScale };
	int height{ cellSize * cellsCount };

	this->size = Size{ width, height };
	this->backColor = Colors::DarkBlue;
	this->foreColor = Colors::White;

	this->bufferViewed = new CHAR_INFO[size.width * size.height];
	this->bufferSaved = new CHAR_INFO[size.width * size.height];
}
