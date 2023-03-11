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
 void GameMap::loadMap(int mapName[10][20])
{
    game_map.max_x = 0;
    game_map.max_y = 0;
   // FILE* fp = NULL;
    //fopen_s(&fp, filename, "rb");
    /*if(fp == NULL)
    {
        cout << "loadMap error";
        return;
    }*/
    for(int i = 0; i < MAP_MAX_Y; i++)
    {
        for(int j = 0; j < MAP_MAX_X; j++)
        {
            game_map.tile[i][j] = mapName[i][j];
        }
    }
    for(int i = 0; i < MAP_MAX_Y; i++)
    {
        for(int j = 0; j < MAP_MAX_X; j++)
        {
            //fscanf(fp, "%d", &game_map.tile[i][j]);
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
     cout << "loadMap ERROR 1 " << endl;
    //game_map.max_x = (game_map.max_x + 1) * TILE_SIZE;
    //game_map.max_y = (game_map.max_y + 1) * TILE_SIZE;
    game_map.start_x = 0;
    game_map.start_y = 0;
    //game_map.file_name = filename;
    //fclose(fp);
     cout << "loadMap ERROR 2 " << endl;
}
void GameMap::loadTiles()
{
    char fileImg[50];
    //FILE* fp = NULL;
    for(int i = 0; i < 5; i++)
    {
        cout << "loadTile ERROR 1 " << endl;

        sprintf_s(fileImg, "map/%d.png", i + 1);
        //fopen_s(&fp, fileImg, "rb");
        //cout << fp << endl;
        //fclose(fp);
        tileMat[i].setTex(fileImg);
        cout << "loadTile ERROR 3 " << endl;
        cout << fileImg;
    }

}
void GameMap::Drawmap()
{
    //int x1 = 0;
    //int x2 = 0;

    //int y1 = 0;
    //int y2 = 0;
    int idRow = 0;
    int idCol = 0;

    //int mapX = 0;
    //int mapY = 0;

    //mapX = game_map.start_x / TILE_SIZE;
    //x1 =  0; /*(game_map.start_x % TILE_SIZE); /* -1*/
    //x2 = x1 + WINDOW_WIDTH;/* + (x1 == 0 ? 0 : TILE_SIZE);*/

    //mapY = game_map.start_y / TILE_SIZE;
    //y1 =  0;/*(game_map.start_y % TILE_SIZE); /* -1;*/
    //y2 = y1 + WINDOW_HEIGHT; /*+ (y1 == 0 ? 0 : TILE_SIZE);*/
    for(int i = 0; i < WINDOW_HEIGHT; i+= TILE_SIZE)
    {
        //mapX = game_map.start_x / TILE_SIZE;
        idRow = i / TILE_SIZE;
        for(int j = 0; j < WINDOW_WIDTH; j += TILE_SIZE)
        {
            idCol = j / TILE_SIZE;
            int val = game_map.tile[idRow][idCol];
            if(val > 0)
            {
                cout << "drawMap ERROR 2 " << endl;
                tileMat[val].setPos(j, i);
                tileMat[val].setCurrentFrame(TILE_SIZE, TILE_SIZE);
                cout << "drawMap ERROR rending"<< endl;
                tileMat[val].render(TILE_SIZE, TILE_SIZE);
            }
            idCol++;
        }
        cout << "drawMap ERROR 3 " << endl;
        idRow++;

    }

}
