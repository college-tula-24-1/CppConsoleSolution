#include "GameViewLibrary.h"

GameView::GameView(int cellSize)
	: Window(), cellSize{cellSize}
{
	this->title = "Game Sea Battle";
	this->style = BorderStyle::Double;

	this->position = Position{ 2, 4 };
	
	int fieldCellsCount{ 10 };
	int widthScale{ 2 };
	int margin{ 2 };

	int width{ ((cellSize * fieldCellsCount) * 2 + margin * cellSize * 4 - 2) * widthScale };
	int height{ cellSize * fieldCellsCount + margin * cellSize * 2 };

	this->size = Size{ width, height };
	this->backColor = Colors::Gray;
	this->foreColor = Colors::Black;

	this->bufferViewed = new CHAR_INFO[size.width * size.height];
	this->bufferSaved = new CHAR_INFO[size.width * size.height];

	this->console->CosoleWindowSize(width, height);

}

void GameView::Show()
{
	Window::Show();

	int row{ this->position.row + cellSize };
	int column{ this->position.column + cellSize * 2 };
	
	FieldView* playerView = new FieldView({ row, column }, cellSize, "Player");
	playerView->Show();

	int fieldCellsCount{ 14 };
	int margin{ 2 };

	column = this->position.column
		+ fieldCellsCount * cellSize * 2;

	FieldView* computerField = new FieldView({ row, column }, cellSize, "Computer");
	computerField->Show();

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

void FieldView::Show()
{
	const int fieldSize{ 10 };

	Window::Show();
	console->ForeColor(this->foreColor);
	console->BackColor(this->backColor);

	for (int i{}; i < fieldSize; i++)
	{
		this->console->WriteWidthPosition(
			{ position.row + 1, position.column + (i + 1) * cellSize * 2 },
			cellSize * 2,
			std::string(1, (char)(65 + i)));
		this->console->WriteWidthPosition(
			{ position.row + cellSize * (i + 2) - 1, position.column + 1 },
			cellSize,
			std::to_string(i + 1));
	}

	for(int row{}; row < fieldSize; row++)
		for (int column{}; column < fieldSize; column++)
			for (int line{}; line < cellSize; line++)
			{
				console->WritePosition(
					{ position.row + cellSize + (row * cellSize + line), 
					position.column + 2 * cellSize + column * cellSize * 2 },
					std::string(cellSize * 2, (char)GameChars::Water));
			}

			
}

SetupView::SetupView(int cellSize)
	: Window(), cellSize{ cellSize }
{
	this->title = "Game Sea Battle";
	this->style = BorderStyle::Double;

	this->position = Position{ 2, 4 };

	int fieldCellsCount{ 10 };
	int widthScale{ 2 };
	int margin{ 2 };

	int width{ ((cellSize * fieldCellsCount) * 2 + margin * cellSize * 4 - 2) * widthScale };
	int height{ cellSize * fieldCellsCount + margin * cellSize * 2 };

	this->size = Size{ width, height };
	this->backColor = Colors::Gray;
	this->foreColor = Colors::Black;

	this->bufferViewed = new CHAR_INFO[size.width * size.height];
	this->bufferSaved = new CHAR_INFO[size.width * size.height];

	this->console->CosoleWindowSize(width, height);
}

void SetupView::Show()
{
	Window::Show();

	int row{ this->position.row + cellSize };
	int column{ this->position.column + cellSize * 2 };

	FieldView* playerView = new FieldView({ row, column }, cellSize, this->title);
	playerView->Show();

}
