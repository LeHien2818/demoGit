/*#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "RenderWindow.hpp"
#include "Entity.hpp"

using namespace std;
//RenderWindow::RenderWindow(){};
//RenderWindow::RenderWindow(const char* title, int w, int h)
//    :window(NULL), renderer(NULL)
//{
//    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);
//    if(window == NULL){
//        cout << "Window cannot Init" << SDL_GetError() << endl;
//    }
//    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//}
//SDL_Texture* RenderWindow::loadTexture(const char* filePath)
//{
//    SDL_Texture* texture = NULL;
//    texture = IMG_LoadTexture(renderer, filePath);
//    if(texture == NULL)
//    {
//        cout << "IMG cannot loaded " << SDL_GetError() << endl ;
//    }
  return texture;

}
void RenderWindow::clearWindow(){
    SDL_RenderClear(renderer);
}
void RenderWindow::render(Entity& p_entity, float out_w, float out_h){
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

}
void RenderWindow::display(){
    SDL_RenderPresent(renderer);
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}


using namespace std;

void renderwindow::RenderWindow(const char* title, int w, int h)
    {

    }
    SDL_Texture* renderwindow::loadTexture(const char* filePath)
    {

    }
    void renderwindow::clearWindow()
    {

    }
    void renderwindow::render(Entity& p_entity, float out_w, float out_h)
    {

    }
    void renderwindow::display(){

    }
    void renderwindow::cleanUp()
    {
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
    }
*/
