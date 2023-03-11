/*#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "RenderWindow.hpp"

using namespace std;

SDL_Texture* LoadTexture(const char *filePath)
{
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, filePath);
    if(texture == NULL)
    {
        cout << "IMG cannot loaded " << SDL_GetError() << endl ;
    }
    return texture;

}*/
