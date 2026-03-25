#include "Platform.h"

Platform::Platform(IGamePlatform* gamePlatform, 
	IPlayerPlatform* playerPlatform)
	: gamePlatform{ gamePlatform },
	playerPlatform{ playerPlatform }{}

IGamePlatform* Platform::GamePlatform()
{
	return gamePlatform;
}

IPlayerPlatform* Platform::PlayerPlatform()
{
	return playerPlatform;
}


