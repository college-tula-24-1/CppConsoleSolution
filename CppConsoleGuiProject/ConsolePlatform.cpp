#include "ConsolePlatform.h"

std::string ConsoleGamePlatform::SetupGame()
{
	Window* welcomeWindow = new Window({ rowStart, columnStart },
		{ fieldSize * widthRate * 2, fieldSize / 2 },
		Colors::Blue,
		Colors::White,
		"Welcome To Sea Battle",
		BorderStyle::Double);
	
	welcomeWindow->Show();

	welcomeWindow->GetConsole()->WritePosition({ rowStart + margin / 2, columnStart + margin }, "Input Player Name:");

	View* welcomeBox = new View({ rowStart + margin, columnStart + margin }, 
								{ fieldSize * widthRate * 2 - 2 * margin, 1 });
	welcomeBox->Show();

	welcomeWindow->GetConsole()->CursorPosition({ rowStart + margin, columnStart + margin });
	std::string name;
	std::getline(std::cin, name);

	welcomeWindow->Hide();

	return name;
}



int ConsolePlayerPlatform::SelectShip()
{
	int columnOffset{ columnStart + fieldSize * cellSize * widthRate + (4 * margin * widthRate)};

	int currentShip{};
	bool isNotOk{ true };
	int index{};

	if (!shipCounts[currentShip])
	{
		for(index = currentShip + 1; index < shipCounts.size(); index++)
			if (shipCounts[index])
			{
				isNotOk = false;
				break;
			}
		if (!isNotOk)
			currentShip = index;
	}

	for (int size{}; size < shipCounts.size(); size++)
	{
		Colors backColor;
		if (shipCounts[size])
		{
			if (size == currentShip)
				backColor = Colors::Blue;
			else
				backColor = Colors::Green;
		}
		else
			backColor = Colors::Magenta;

		shipViews[size]->BackColor(backColor);
		shipViews[size]->Show();

		View::GetConsole()->BackColor(Colors::Gray);
		View::GetConsole()->ForeColor(Colors::Black);
		View::GetConsole()->WritePosition(
			{ rowStart + margin + (size * 2) * cellSize + 2, 
			  columnOffset + margin * cellSize },
			std::to_string(shipCounts[size]));
	}

	Key key = Key::Enter;
	bool isQuit{ false };


	while (true)
	{
		if (View::GetConsole()->KeyPressed())
		{
			key = (Key)View::GetConsole()->GetChar();

			switch (key)
			{
			case Key::ArrowLeft:
			case Key::ArrowUp:
				isNotOk = true;
				for(index = currentShip - 1; index >= 0; index--)
					if (shipCounts[index])
					{
						isNotOk = false;
						break;
					}
				if (!isNotOk)
					currentShip = index;
				break;

			case Key::ArrowRight:
			case Key::ArrowDown:
				isNotOk = true;
				for(index = currentShip + 1; index < shipCounts.size(); index++)
					if (shipCounts[index])
					{
						isNotOk = false;
						break;
					}
				if (!isNotOk)
					currentShip = index;
				break;

			case Key::Enter:
				isQuit = true;
				break;

			case Key::Space:
				break;
			case Key::Esc:
				break;
			default:
				break;
			}

			if (isQuit) break;

			for (int size{}; size < shipCounts.size(); size++)
			{
				Colors backColor;
				if (shipCounts[size])
				{
					if (size == currentShip)
						backColor = Colors::Blue;
					else
						backColor = Colors::Green;
				}
				else
					backColor = Colors::Magenta;
				
				shipViews[size]->BackColor(backColor);
			}
		}
	}

	return currentShip + 1;
}

Ship* ConsolePlayerPlatform::SetShip(int size)
{
	int top{ rowStart + margin * cellSize };
	int bottom{ top + fieldSize * cellSize };
	int left{ columnStart + margin * cellSize * widthRate };
	int right{ left + fieldSize * cellSize * widthRate };

	int width{ size * cellSize * widthRate };
	int height{ cellSize };


	int shipRow{ top };
	int shipColumn{ left };
	int row{}, column{};
	bool direction{};

	View* shipView = new View({ shipRow, shipColumn },
		{ width, height },
		Colors::Magenta,
		Colors::White);

	shipView->Show();
	
	Key key;
	bool isQuit{};

	Ship* ship{ nullptr };

	while (true)
	{
		isQuit = false;
		if (View::GetConsole()->KeyPressed())
		{
			key = (Key)View::GetConsole()->GetChar();
			shipView->Hide();

			switch (key)
			{
			case Key::ArrowLeft:
				if (shipColumn > left)
				{
					shipColumn -= cellSize * widthRate;
					column--;
				}
				break;
			case Key::ArrowRight:
				if (direction)
				{
					if (shipColumn < right - cellSize * widthRate)
					{
						shipColumn += cellSize * widthRate;
						column++;
					}
						
				}
				else
				{
					if (shipColumn + size * widthRate * cellSize < right)
					{
						shipColumn += cellSize * widthRate;
						column++;
					}
				}
				break;
			case Key::ArrowUp:
				if (shipRow > top)
				{
					shipRow -= cellSize;
					row--;
				}
				break;
			case Key::ArrowDown:
				if (direction)
				{
					if (shipRow + size * cellSize < bottom)
					{
						shipRow += cellSize;
						row++;
					}
				}
				else
				{
					if (shipRow < bottom - cellSize)
					{
						shipRow += cellSize;
						row++;
					}
				}
				break;
			case Key::Enter:
			{
				DirectionShip dirShip = (direction) ?
					DirectionShip::Vertical : DirectionShip::Horizontal;

				ship = new Ship({ row, column }, size, dirShip);

				isQuit = this->IsSetShip(ship);
				
				if (!isQuit)
				{
					delete ship;
					ship = nullptr;
				}
				break;
			}
			case Key::Space:
			{
				direction = !direction;

				int w = width;
				width = height * 2;
				height = w / 2;

				shipView->Resize({ width, height });
				break;
			}
			case Key::Esc:
				isQuit = true;
				break;
			default:
				break;
			}

			if (isQuit) break;

			shipView->Move({ shipRow, shipColumn });
			shipView->Show();
		}
	}

	return ship;
}

void ConsolePlayerPlatform::ShipsShow()
{
	int top{ rowStart + margin * cellSize };
	int left{ columnStart + margin * cellSize * widthRate };

	for (Ship* ship : flotilla)
	{
		int shipRow{ top + ship->Row() * cellSize };
		int shipColumn{ left + ship->Column() * cellSize * widthRate };
		int shipWidth{ ship->Size() * cellSize * widthRate };
		int shipHeight{ cellSize };

		if (ship->Direction() == DirectionShip::Vertical)
		{
			int w = shipWidth;
			shipWidth = shipHeight * 2;
			shipHeight = w / 2;
		}

		View* shipView = new View({ shipRow, shipColumn },
			{ shipWidth, shipHeight },
			Colors::Green, Colors::White);
		shipView->Show();
	}
}

bool ConsolePlayerPlatform::IsSetShip(Ship* ship)
{
	bool isNotSet{ false };

	for (Ship* s : flotilla)
	{
		int row{ ship->Row() };
		int column{ ship->Column() };

		for (int p{}; p < ship->Size(); p++)
		{
			for (int rowDx{ -1 }; rowDx < 2; rowDx++)
			{
				for (int columnDx{ -1 }; columnDx < 2; columnDx++)
				{
					isNotSet = s->IsPoint({ row + rowDx, column + columnDx });
					if (isNotSet) break;
				}
				if (isNotSet) break;
			}
			if (isNotSet) break;

			(ship->Direction() == DirectionShip::Horizontal) ? column++ : row++;
		}
		if (isNotSet) break;
	}

	return !isNotSet;
}

ConsolePlayerPlatform::ConsolePlayerPlatform()
{
	int columnOffset{ columnStart + fieldSize * cellSize * widthRate + (4 * margin * widthRate) };

	for (int size{}; size < shipViews.size(); size++)
	{
		View* shipView = new View(
			{ rowStart + margin + (size * 2) * cellSize + 1, columnOffset + 2 * margin * cellSize },
			{ (size + 1) * cellSize * widthRate, cellSize },
			Colors::Green, Colors::White);
		shipViews[size] = shipView;
	}

}

std::vector<Ship*> ConsolePlayerPlatform::SetFlotilla(std::string name)
{
	SetupView* setFlotillaView = new SetupView({rowStart, columnStart}, cellSize);
	setFlotillaView->Title() = name;
	setFlotillaView->Show();

	Ship* ship;
	int selectShip;

	while (true)
	{
		selectShip = this->SelectShip();
		ship = this->SetShip(selectShip);
		if (ship)
		{
			flotilla.push_back(ship);
			shipCounts[selectShip - 1]--;
		}
		this->ShipsShow();

		int countsAll = std::accumulate(shipCounts.begin(), shipCounts.end(), 0);
		if (!countsAll)
			break;
	}
	
	setFlotillaView->Hide();

	return flotilla;
}
