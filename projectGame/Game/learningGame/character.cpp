#include "Character.hpp"
#include "amoObj.hpp"
#include "RenderWindow.hpp"
#include "Commonfunc.hpp"
#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;
gameCharacter::gameCharacter()
{
    pos = Vector2f(0, 0);
    currentFrame.x = 0;
    currentFrame.y = 0;
}
gameCharacter::gameCharacter(Vector2f p_pos, SDL_Texture* p_tex, float in_w, float in_h)

{
    pos = p_pos;
    tex = p_tex;
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = in_w;
    currentFrame.h = in_h;
}

//SDL_Rect gameCharacter::getCurrentFrame(){
 //   return currentFrame;
//}
//SDL_Texture* gameCharacter::getTex(){
//    return tex;
//}
void gameCharacter::handdleInputAction(SDL_Event e){
        x_val = 0;
        y_val = 0;
    if(e.type == SDL_KEYDOWN){
        switch(e.key.keysym.sym){
        case SDLK_UP:
                y_val -= 12;
                break;
        case SDLK_DOWN:
                y_val += 12;
                break;
        case SDLK_RIGHT:
                x_val += 12;
                break;
        case SDLK_LEFT:
                x_val -= 12;
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
            amoObject* p_amo = new amoObject() ;
            if(e.button.button == SDL_BUTTON_LEFT)
            {
                p_amo->setCurrentFrameAMO(WIDTH_LASER, HEIGHT_LASER);
                p_amo->setTex("laser.png");
                p_amo->setType(amoObject::LASER);
                p_amo->setIsMove(true);
            }
            else if(e.button.button == SDL_BUTTON_RIGHT)
            {
                p_amo->setCurrentFrameAMO(WIDTH_SHPERE, HEIGHT_LASER);
                p_amo->setTex("sphere.png");
                p_amo->setType(amoObject::SPHERE);
                p_amo->setIsMove(true);
            }
        p_amo->getPos().x = this->pos.x + 64;
        p_amo->getPos().y = this->pos.y + 64;
        p_amoList.push_back(p_amo);
    }else if(e.type == SDL_MOUSEBUTTONUP){

    }else{}
 }
 void gameCharacter::handdleMove(){
    pos.x += x_val;
    if(pos.x < 0 || pos.x  > WINDOW_WIDTH - 200 ){
        pos.x -= x_val;
    }
    pos.y += y_val;
    if(pos.y < 0 || pos.y  > WINDOW_HEIGHT - 200 ){
        pos.y -= y_val;
    }
 }
void gameCharacter::setAmoList(vector<amoObject*> amo_list)
{
    p_amoList = amo_list;
}
vector<amoObject*> gameCharacter::getAmoList()
{
    return p_amoList;
}
