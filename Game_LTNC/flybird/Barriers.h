#ifndef BARRIERS_H_
#define BARRIERS_H_

#include <SDL.h>
#include "definitions.h"

struct Barrier
{
    SDL_Rect topSRC, topDST;
    SDL_Rect bottomDST, bottomSRC;

    void renderPipe(SDL_Renderer *renderer, SDL_Texture *tex)
    {
        SDL_RenderCopyEx(renderer, tex, &topSRC, &topDST, 0, NULL, SDL_FLIP_VERTICAL);
        SDL_RenderCopy(renderer, tex, &bottomSRC, &bottomDST);
    }

    Barrier(int x, int height)
    {
        bottomDST.x = x;
        bottomDST.y = HEIGHT - height;
        bottomDST.w = BARRIER_WIDTH;
        bottomDST.h = height;

        bottomSRC.x = 0;
        bottomSRC.y = 0;
        bottomSRC.w = BARRIER_WIDTH_SOURCE;
        bottomSRC.h = height;

        topDST.x = x;
        topDST.y = 0;
        topDST.w = BARRIER_WIDTH;
        topDST.h = HEIGHT - height - BARRIERGAP;

        topSRC.x = topSRC.y = 0;
        topSRC.w = BARRIER_WIDTH_SOURCE;
        topSRC.h = topDST.h;

        passed = false;
    }
    bool passed;
};

#endif
