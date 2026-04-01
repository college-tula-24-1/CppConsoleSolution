#include "Player.h"

Player::Player(std::string name) 
	: name{ name },
	battleField{ new Field() }{}

Player::Player() : Player("Computer"){}

std::string& Player::Name()
{
	return name;
}

Field*& Player::BattleField()
{
	return battleField;
}

std::vector<Ship*>& Player::Flotilla()
{
	return flotilla;
}

int Player::FlotillaSize()
{
	int size{};
	for (auto ship : flotilla)
		if (!ship->IsDeed())
			size++;
	return size;
}

HitType Player::CheckShot(Point point)
{
	HitType hit{ battleField->CheckShot(point) };
	battleField->SetCellShot(point);

	if (hit == HitType::Beside)
		return hit;

	for (auto ship : flotilla)
		if (ship->IsPoint(point))
		{
			ship->Damage()++;
			if (ship->IsDeed())
				return HitType::Destroy;
			else
				return HitType::Wound;
		}
}

HumanPlayer::HumanPlayer(std::string name, 
	IPlayerPlatform* playerPlatform)
	: Player(name),
	playerPlatform{ playerPlatform }{}

IPlayerPlatform*& HumanPlayer::PlayerPlatfor()
{
	return playerPlatform;
}

void HumanPlayer::SetFlotilla()
{
	//this->flotilla = this->playerPlatform->SetFlotilla(this->Name());

	this->flotilla.push_back(new Ship({ 0, 1 }, 1, DirectionShip::Horizontal));
	this->flotilla.push_back(new Ship({ 1, 5 }, 4, DirectionShip::Horizontal));
	this->flotilla.push_back(new Ship({ 3, 9 }, 3, DirectionShip::Vertical));
	this->flotilla.push_back(new Ship({ 4, 3 }, 1, DirectionShip::Horizontal));
	this->flotilla.push_back(new Ship({ 4, 6 }, 2, DirectionShip::Horizontal));
	this->flotilla.push_back(new Ship({ 5, 0 }, 2, DirectionShip::Vertical));
	this->flotilla.push_back(new Ship({ 6, 5 }, 1, DirectionShip::Horizontal));
	this->flotilla.push_back(new Ship({ 8, 0 }, 2, DirectionShip::Horizontal));
	this->flotilla.push_back(new Ship({ 8, 7 }, 3, DirectionShip::Horizontal));
	this->flotilla.push_back(new Ship({ 9, 4 }, 1, DirectionShip::Horizontal));

	this->battleField->SetShips(this->flotilla);
}

Point HumanPlayer::Shot()
{
	return this->playerPlatform->Shot();
}

void ComputerPlayer::SetFlotilla()
{
	this->flotilla.push_back(new Ship({ 0, 1 }, 1, DirectionShip::Horizontal));
	this->flotilla.push_back(new Ship({ 1, 5 }, 4, DirectionShip::Horizontal));
	this->flotilla.push_back(new Ship({ 3, 9 }, 3, DirectionShip::Vertical));
	this->flotilla.push_back(new Ship({ 4, 3 }, 1, DirectionShip::Horizontal));
	this->flotilla.push_back(new Ship({ 4, 6 }, 2, DirectionShip::Horizontal));
	this->flotilla.push_back(new Ship({ 5, 0 }, 2, DirectionShip::Vertical));
	this->flotilla.push_back(new Ship({ 6, 5 }, 1, DirectionShip::Horizontal));
	this->flotilla.push_back(new Ship({ 8, 0 }, 2, DirectionShip::Horizontal));
	this->flotilla.push_back(new Ship({ 8, 7 }, 3, DirectionShip::Horizontal));
	this->flotilla.push_back(new Ship({ 9, 4 }, 1, DirectionShip::Horizontal));
}
