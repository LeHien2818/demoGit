#pragma once
#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <cstdio>
#include "Entity.hpp"


using namespace std;
using namespace renderwindow;


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
    void loadMap(int mapName[10][20]);
    void loadTiles();
    void Drawmap();
    MAP& getGame_Map()
    {
        return game_map;
    }
private:
    MAP game_map;
    TileMat tileMat[Max_Tiles];
    Vector2f posTile;
};
