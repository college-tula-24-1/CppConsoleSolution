#include "Game.h"

Game::Game(Platform* platform)
	: platform{ platform },
	players{}{}

Game::Game() : Game(nullptr) {}



void Game::Setup()
{
	std::string name{ this->platform->GamePlatform()->SetupGame() };

	players[0] = new HumanPlayer(name, this->platform->PlayerPlatform());
	players[1] = new ComputerPlayer();

	for (auto player : players)
		player->SetFlotilla();
}

void Game::Process()
{
	HitType hit;
	Point point;

	this->platform->GamePlatform()->ViewGame();

	//while (true)
	//{
	//	point = players[currentPlayer]->Shot();
	//	hit = players[!currentPlayer]->CheckShot(point);

	//	this->platform->GamePlatform()->ViewShot(point, currentPlayer, hit);

	//	if (hit == HitType::Destroy)
	//	{
	//		if (players[!currentPlayer]->FlotillaSize() == 0)
	//			break;
	//	}

	//	if (hit == HitType::Beside)
	//		currentPlayer = !currentPlayer;
	//}
}
