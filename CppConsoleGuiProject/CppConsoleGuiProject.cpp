#include <iostream>

#include "ConsolePlatform.h"
#include "Game.h"


int main()
{
    Game* game = new Game(new Platform(
        new ConsoleGamePlatform(),
        new ConsolePlayerPlatform()));

    game->Setup();
    game->Process();
}
