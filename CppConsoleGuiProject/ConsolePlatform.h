#pragma once
#include <iostream>
#include <array>
#include <numeric>
#include <ranges>

#include "Platform.h"
#include "GameViewLibrary.h"
#include "Game.h"


class ConsolePlatform
{};

class ConsoleGamePlatform : public IGamePlatform
{
	Game* game;
	GameView* gameView;

	int fieldSize{ 10 };
	int cellSize{ 2 };
	int margin{ 2 };

	int widthRate{ 2 };
	int rowStart{ 3 };
	int columnStart{ 5 };

	void FlotillaShow();

public:
	void SetGame(Game* game);

	std::string SetupGame() override;
	void GameShow() override;
	void ShotShow(Point point, bool currentPlayer, HitType type) override;
	void GameOver() override {};
};

class ConsolePlayerPlatform : public IPlayerPlatform
{
	std::vector<Ship*> flotilla;

	std::array<int, 4> shipCounts{ 4, 3, 2, 1 };
	std::array<View*, 4> shipViews{};

	int fieldSize{ 10 };
	int cellSize{ 2 };
	int margin{ 2 };

	int widthRate{ 2 };
	int rowStart{ 2 };
	int columnStart{ 4 };

	int SelectShip();
	Ship* SetShip(int size);
	void ShipsShow();
	bool IsSetShip(Ship* ship);
public:
	ConsolePlayerPlatform();

	std::vector<Ship*> SetFlotilla(std::string name) override;
	Point Shot() override;
};

