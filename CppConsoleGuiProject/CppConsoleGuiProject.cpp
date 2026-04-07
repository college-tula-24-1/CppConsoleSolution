#include <iostream>

#include "ConsolePlatform.h"
#include "Game.h"


int main()
{
    ConsoleGamePlatform* consoleGamePlatform
        = new ConsoleGamePlatform();

    Game* game = new Game(new Platform(
        consoleGamePlatform,
        new ConsolePlayerPlatform()));

    consoleGamePlatform->SetGame(game);

    game->Setup();
    game->Process();
}
