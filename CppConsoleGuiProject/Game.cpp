#include "Game.h"

Game::Game()
{
	HumanPlayer* humanPlayer = new HumanPlayer();
	players[0] = humanPlayer;

	ComputerPlayer* computerPlayer = new ComputerPlayer();
	players[1] = computerPlayer;
}

Game::Game(Platform* platform)
	: platform{ platform }
{
	HumanPlayer* humanPlayer = new HumanPlayer();

}

void Game::Setup()
{
	for (auto player : players)
		player->SetFlotilla();
}

void Game::Process()
{
	HitType hit;
	Point point;

	while (true)
	{
		point = players[currentPlayer]->Shot();
		hit = players[!currentPlayer]->CheckShot(point);

		if (hit == HitType::Destroy)
		{
			if (players[!currentPlayer]->FlotillaSize() == 0)
				break;
		}

		if (hit == HitType::Beside)
			currentPlayer = !currentPlayer;
	}
}
