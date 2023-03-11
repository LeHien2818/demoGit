#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include<cstdio>

#include "Entity.hpp"
#include "Math.hpp"
#include "amoObj.hpp"
#include "Character.hpp"
#include "RenderWindow.hpp"
#include "game_map.hpp"
#include "ThreatObj.hpp"
#include "MapMatrix.hpp"
using namespace std;
using namespace renderwindow;

int main(int argc, char* argv[]){
    if((SDL_Init(SDL_INIT_EVERYTHING)) > 0 ){
       cout << "SDL_Init failed" <<  SDL_GetError() << endl;
    }
    RenderWindow("Game v1.1", WINDOW_WIDTH, WINDOW_HEIGHT);

    SDL_Texture* bckgrTexture = loadTexture("pxGrass.png");
    SDL_Texture* charObject = loadTexture("charDemo.png");
    SDL_Texture* test = loadTexture("map/2.png");

    Entity backgroundImage(Vector2f(0, 0), bckgrTexture, 32, 32);
    gameCharacter charInGame1(Vector2f(300, 300), charObject, 64 , 64);
    ThreatObject* p_threat = new ThreatObject();
    p_threat->setTex("charDemo.png");
    p_threat->setPos(1200, 640 * 0.4);
    p_threat->setXVal(15);
    GameMap game_map;
    SDL_Event e;

    bool gameRunning = true;
    while(gameRunning){
            while(SDL_PollEvent(&e)){
                if(e.type == SDL_QUIT ){
                    gameRunning = false;
                }
                charInGame1.handdleInputAction(e);
            }
             clearWindow();
             SDL_Delay(5);
             charInGame1.checkMap(game_map);
             charInGame1.handdleMove();
             game_map.loadMap(mapDbs_1);
             game_map.loadTiles();
            // backgroundImage.render(WINDOW_WIDTH, WINDOW_HEIGHT)
             charInGame1.render(64 * 2, 64 * 2);
             game_map.Drawmap();
             for(long long unsigned int i = 0; i < charInGame1.getAmoList().size(); i++)
             {
                 vector<amoObject*> amoList = charInGame1.getAmoList();
                 amoObject* p_amo = amoList.at(i);
                 if(p_amo != nullptr)
                 {
                     if(p_amo->getIsMove())
                     {
                         if(p_amo->getType() == 1) p_amo->render(WIDTH_LASER, HEIGHT_LASER);
                         else if(p_amo->getType() == 2) p_amo->render(WIDTH_SHPERE, HEIGHT_SPHERE);
                         p_amo->handdleMove(WINDOW_WIDTH, WINDOW_HEIGHT);

                     }
                     else
                     {
                         if(p_amo != nullptr)
                         {
                             amoList.erase(amoList.begin() + i);
                             charInGame1.setAmoList(amoList);
                             delete p_amo;
                             p_amo = nullptr;
                         }
                     }
                 }
             }
             p_threat->handleMove(WINDOW_WIDTH, WINDOW_HEIGHT);
             SDL_Delay(5);
             p_threat->render(128, 128);
             display();

    }
    cleanUp();
    SDL_Quit();

    return 0;
}
