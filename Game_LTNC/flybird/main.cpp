#include "Game.h"
#include "definitions.h"
#undef main

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    Game game("Flying bird", WIDTH, HEIGHT);

    game.Start();

    return 0;
}
