#pragma once
#include "Window.h"

enum class GameChars
{
	Water = 177,
	Deck = 219
};

class GameView : public View
{
protected:
	int cellSize;
public:
	GameView(int cellSize);

	void Show() override;
};

class FieldView : public Window
{

};

class ShipView : public View
{

};

class CursorView : public View
{

};

