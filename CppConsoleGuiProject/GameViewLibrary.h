#pragma once
#include "Window.h"
#include "Game.h"

enum class GameChars
{
	Water = 177,
	Deck = 219
};


class FieldView : public Window
{
protected:
	int cellSize;
public:
	FieldView(Position position,
		int cellSize,
		std::string title);

	void Show() override;
};

class GameView : public Window
{
protected:
	int cellSize;
	std::array<Player*, 2> players;
	std::array<FieldView*, 2> fields;
public:
	GameView(std::array<Player*, 2> players, int cellSize);

	void Show() override;

	std::array<FieldView*, 2> Fields();
	std::array<Player*, 2> Players();
};

class SetupView : public Window
{
protected:
	int cellSize;
public:
	SetupView(Position position, int cellSize);

	void Show() override;
};

class ShipView : public View
{

};

class CursorView : public View
{

};

