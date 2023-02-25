#ifndef RENDERWINDOW_HPP_INCLUDED
#define RENDERWINDOW_HPP_INCLUDED
#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "Entity.hpp"
const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 600;
const int WIDTH_LASER = 35;
const int HEIGHT_LASER = 10;
const int WIDTH_SHPERE = 15;
const int HEIGHT_SPHERE = 15;
const int TILE_SIZE = 64;
const int MAP_MAX_X = 400;
const int MAP_MAX_Y = 10;

inline SDL_Window* window;
inline SDL_Renderer* renderer;
using namespace std;
typedef struct MAP
{
  MAP(){};
  int start_x, start_y;

  int max_x, max_y;



  int tile[MAP_MAX_Y][MAP_MAX_X];
  char* file_name;
};
namespace renderwindow
{

   inline void RenderWindow(const char* title, int w, int h)
    {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
        if(window == NULL){
            cout << "Window cannot Init" << SDL_GetError() << endl;
        }
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }
   inline SDL_Texture* loadTexture(const char* filePath)
    {
        SDL_Texture* texture = NULL;
        texture = IMG_LoadTexture(renderer, filePath);
        if(texture == NULL)
        {
            cout << "IMG cannot loaded " << SDL_GetError() << endl ;
        }
        return texture;
    };
   inline void clearWindow()
    {
        SDL_RenderClear(renderer);
    };
  /*inline void render(Entity& p_entity, float out_w, float out_h)
    {
        SDL_Rect src;
            src.x = p_entity.getCurrentFrame().x;
            src.y = p_entity.getCurrentFrame().y;
            src.h = p_entity.getCurrentFrame().h;
            src.w = p_entity.getCurrentFrame().w;
        SDL_Rect dst;
            dst.x = p_entity.getPos().x;
            dst.y = p_entity.getPos().y;
            dst.h = out_h;
            dst.w = out_w ;
        SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
    };*/
   inline void display(){
        SDL_RenderPresent(renderer);
        };
   inline void cleanUp()
    {
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
    };
}



//class RenderWindow
//{
//public:
/*    RenderWindow();
    RenderWindow(const char* title, int w, int h);
    SDL_Texture* loadTexture(const char* filePath);
    SDL_Window* getwindow(){
        return window;
    }
    SDL_Renderer* getrenderer(){
        return renderer;
    }
    void clearWindow();
    void render(Entity& p_entity, float out_w, float out_h);
    void display();
    void cleanUp();

//private:
    SDL_Window* window;
    SDL_Renderer* renderer;

*/
//};




#endif // RENDERWINDOW_HPP_INCLUDED
