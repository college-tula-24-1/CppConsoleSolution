#include "GameViewLibrary.h"

GameView::GameView(int cellSize)
	: View(), cellSize{ cellSize }
{
	//this->title = "Game Sea Battle";
	//this->style = BorderStyle::Double;

	this->position = Position{ 2, 4 };
	
	int fieldCellsCount{ 12 };
	int widthScale{ 2 };
	int margin{ 2 };

	int width{ ((cellSize * fieldCellsCount) * 2 + margin * cellSize * 3) * widthScale };
	int height{ cellSize * fieldCellsCount + margin * cellSize * 2 };

	this->size = Size{ width, height };
	this->backColor = Colors::Gray;
	this->foreColor = Colors::Black;
}

void GameView::Show()
{
	View::Show();
}
