#include "game_map.hpp"
#include "Entity.hpp"


using namespace std;
using namespace renderwindow;
TileMat::TileMat()
{
    ;
}
TileMat::TileMat(Vector2f p_pos, SDL_Texture* p_tex, float in_w, float in_h)
{
    pos = p_pos;
    tex = p_tex;
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = in_w;
    currentFrame.h = in_h;
}
GameMap::GameMap()
{
    ;
}
 void GameMap::loadMap(char* filename)
{
    FILE* fp = NULL;
    fopen_s(&fp, filename, "rb");
    if(fp == NULL)
    {
        cout << "loadMap error";
        return;
    }
    for(int i = 0; i < MAP_MAX_Y; i++)
    {
        for(int j = 0; j < MAP_MAX_X; j++)
        {
            fscanf(fp, "%d", &game_map.tile[i][j]);
            int val = game_map.tile[i][j];
            if(val > 0)
            {
                if(j > game_map.max_x)
                {
                    game_map.max_x = j;
                }
                if(i > game_map.max_y)
                {
                    game_map.max_y = i;
                }
            }
        }
    }
    game_map.max_x = (game_map.max_x + 1) * TILE_SIZE;
    game_map.max_y = (game_map.max_y + 1) * TILE_SIZE;
    game_map.start_x = 0;
    game_map.start_y = 0;
    game_map.file_name = filename;
    fclose(fp);
}
void GameMap::loadTiles(SDL_Renderer* screen)
{
    char fileImg[10];
    FILE* fp = NULL;
    for(int i = 0; i < Max_Tiles; i++)
    {
        sprintf_s(fileImg, "map/%d.png", i);
        fopen_s(&fp, fileImg, "rb");
        if(fp == NULL)
        {
            continue;
        }
        fclose(fp);
        tileMat[i].setTex(fileImg);
    }

}
void GameMap::Drawmap(SDL_Renderer* screen)
{

}
