#include "Entity.hpp"
//#include "RenderWindow.hpp"
#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;
Entity::Entity()
    :pos(Vector2f(0, 0))
{
    currentFrame.x = 0;
    currentFrame.y = 0;
}
Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex, float in_w, float in_h)
    :pos(p_pos), tex(p_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = in_w;
    currentFrame.h = in_h;
}

SDL_Rect Entity::getCurrentFrame(){
    return currentFrame;
}
SDL_Texture* Entity::getTex(){
    return tex;
}
/*void Entity::handdleInputAction(SDL_Event e){
        x_val = 0;
        y_val = 0;
    if(e.type == SDL_KEYDOWN){
        switch(e.key.keysym.sym){
        case SDLK_UP:
                y_val -= 7;
                break;
        case SDLK_DOWN:
                y_val += 7;
                break;
        case SDLK_RIGHT:
                x_val += 7;
                break;
        case SDLK_LEFT:
                x_val -= 7;
                break;
        default:
            break;
        }
    }
    else if(e.type == SDL_KEYUP){
        switch(e.key.keysym.sym){
        case SDLK_UP:
                y_val += 0;
                break;
        case SDLK_DOWN:
                y_val -= 0;
                break;
        case SDLK_RIGHT:
                x_val -= 0;
                break;
        case SDLK_LEFT:
                x_val += 0;
                break;
        default:
            break;
        }
    }else if(e.type == SDL_MOUSEBUTTONDOWN){

    }else if(e.type == SDL_MOUSEBUTTONUP){

    }else{}
 }
 void Entity::handdleMove(){
    pos.x += x_val;
    if(pos.x < 0 || pos.x  > WINDOW_WIDTH - 200 ){
        pos.x -= x_val;
    }
    pos.y += y_val;
    if(pos.y < 0 || pos.y  > WINDOW_HEIGHT - 200 ){
        pos.y -= y_val;
    }
 }
 */

