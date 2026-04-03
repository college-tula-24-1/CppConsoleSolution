#pragma once
#include <array>

#include "Player.h"
#include "Platform.h"

class Game
{
	std::array<Player*, 2> players{};
	bool currentPlayer{ false };

	Platform* platform;

public:
	Game();
	Game(Platform* platform);

	std::array<Player*, 2> Players();

	void Setup();
	void Process();
};

