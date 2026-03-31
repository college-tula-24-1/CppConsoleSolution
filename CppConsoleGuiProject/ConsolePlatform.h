#pragma once
#include <iostream>

#include "Platform.h"
#include "GameViewLibrary.h"

class ConsolePlatform
{};

class ConsoleGamePlatform : public IGamePlatform
{
	int FieldSize{ 10 };
	int cellSize{ 2 };
	int margin{ 2 };

public:
	std::string SetupGame() override;
	void ViewGame() override {};
	void ViewShot(Point point, bool currentPlayer, HitType type) override {};
	void GameOver() override {};
};

class ConsolePlayerPlatform : public IPlayerPlatform
{
public:
	std::vector<Ship*> SetFlotilla() override;
	Point Shot() override { return {}; }
};

