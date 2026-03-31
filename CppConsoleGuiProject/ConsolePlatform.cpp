#include "ConsolePlatform.h"

std::string ConsoleGamePlatform::SetupGame()
{
	Window* welcomeWindow = new Window({ 3, 8 },
		{ 32, 7 },
		Colors::Blue,
		Colors::White,
		"Welcome To Sea Battle",
		BorderStyle::Double);
	
	welcomeWindow->Show();

	welcomeWindow->GetConsole()->WritePosition({ 5, 11 }, "Input Player Name:");

	View* welcomeBox = new View({ 7, 11 }, { 26, 1 });
	welcomeBox->Show();

	welcomeWindow->GetConsole()->CursorPosition({ 7, 11 });
	std::string name;
	std::getline(std::cin, name);

	welcomeWindow->Hide();

	return name;
}

std::vector<Ship*> ConsolePlayerPlatform::SetFlotilla()
{
	//GameView* 


	return std::vector<Ship*>();
}
