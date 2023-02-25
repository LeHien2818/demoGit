#pragma once
#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <cstdio>
#include "Entity.hpp"

using namespace std;
using namespace renderwindow;
const int Max_Tiles = 20;

class TileMat : public Entity
{
public:
    TileMat();
    TileMat(Vector2f p_pos, SDL_Texture* p_tex, float in_w, float in_h);

};

class GameMap
{
public:
    GameMap();
    void loadMap(char* filename);
    void loadTiles(SDL_Renderer* screen);
    void Drawmap(SDL_Renderer* screen);
private:
    MAP game_map;
    TileMat tileMat[Max_Tiles];
};
