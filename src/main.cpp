#include "../include/MageGame.h"
#include "../include/globals.h"
#include "../include/Log.h"

using namespace MageEngine;

int main ( int argc, char** argv )
{
    MageGame game(800, 600, "Test");
    game.Run();
    closeLog();
    SDL_Quit();
    return 0;
}
