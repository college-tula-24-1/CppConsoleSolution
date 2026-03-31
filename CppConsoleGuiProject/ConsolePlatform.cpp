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

	return currentShip;
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
	SetupView* setFlotillaView = new SetupView(cellSize);
	setFlotillaView->Title() = name;
	setFlotillaView->Show();

	this->SelectShip();

	setFlotillaView->GetConsole()->GetChar();
	setFlotillaView->Hide();


	return std::vector<Ship*>();
}
