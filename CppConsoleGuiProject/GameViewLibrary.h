#pragma once
#include "Window.h"

enum class GameChars
{
	Water = 177,
	Deck = 219
};

class GameView : public Window
{
protected:
	int cellSize;
public:
	GameView(int cellSize);

	void Show() override;
};

class SetupView : public Window
{
protected:
	int cellSize;
public:
	SetupView(Position position, int cellSize);

	void Show() override;
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

class ShipView : public View
{

};

class CursorView : public View
{

};

