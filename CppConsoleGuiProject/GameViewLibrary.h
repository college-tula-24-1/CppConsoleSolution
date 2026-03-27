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

};

class FieldView : public Window
{
protected:
	int cellSize;
public:
	FieldView(Position position, 
		int cellSize, 
		std::string title);
};

class ShipView : public View
{

};

class CursorView : public View
{

};

