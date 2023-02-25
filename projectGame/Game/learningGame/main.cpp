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

using namespace std;
using namespace renderwindow;

int main(int argc, char* argv[]){
    if((SDL_Init(SDL_INIT_EVERYTHING)) > 0 ){
       cout << "SDL_Init failed" <<  SDL_GetError() << endl;
    }
    RenderWindow("Game v1.1", WINDOW_WIDTH, WINDOW_HEIGHT);

    SDL_Texture* bckgrTexture = loadTexture("pxGrass.png");
    SDL_Texture* charObject = loadTexture("charDemo.png");
   // SDL_Texture* laserBullet = loadTexture("laser.png");
   // SDL_Texture* sphereBullet = loadTexture("sphere.png");

    Entity backgroundImage(Vector2f(0, 0), bckgrTexture, 32, 32);
    gameCharacter charInGame1(Vector2f(300, 300), charObject, 64 , 64);



    /*Entity entities[3] = {Entity(0, 0, bckgrTexture),
                          Entity(32 * 4, 0, bckgrTexture),
                          Entity(64 * 4, 0, bckgrTexture)};*/
   /* vector<Entity> entities = {Entity(Vector2f(0, 0), bckgrTexture),
                               Entity(Vector2f(32 * 4 , 0), bckgrTexture),
                               Entity(Vector2f(64 * 4, 0), bckgrTexture),
                               Entity(Vector2f(96 * 4, 0), bckgrTexture)};
        {
            Entity test(Vector2f(128 * 4, 0), bckgrTexture);
            entities.push_back(test);

        }*/
        /* for(Entity& p : entities){
                window.render(p);
                }

            window.display();*/





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
             charInGame1.handdleMove();
             backgroundImage.render(WINDOW_WIDTH, WINDOW_HEIGHT);
             charInGame1.render(64 * 2, 64 * 2);
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
             display();

    }
    cleanUp();
    SDL_Quit();

    return 0;
}
