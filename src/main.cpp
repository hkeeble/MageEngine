#include "engine/Application/MageGame.h"
#include "engine/globals.h"
#include "engine/Application/Log.h"

using namespace MageEngine;

#if _WIN32
#undef main
#elif _WIN64
#undef main
#endif

int main ( int argc, char** argv )
{
    MageGame game(800, 600, "Test");
    game.Run();
    closeLog();
    SDL_Quit();
    return 0;
}
