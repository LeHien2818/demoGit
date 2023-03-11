#include "amoObj.hpp"
using namespace std;
amoObject::amoObject()
{
    pos = Vector2f(0, 0);
    currentFrame.x = 0;
    currentFrame.y = 0;
    is_move = false;
    amoType = NONE;
}
amoObject::amoObject(Vector2f p_pos, SDL_Texture* p_tex, float in_w, float in_h)
{
    pos = p_pos;
    tex = p_tex;
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = in_w;
    currentFrame.h = in_h;
    is_move = false;
    amoType = NONE;
}
void amoObject::handdleInput(SDL_Event e)
{
     x_val_ = 0;
     y_val_ = 0;
     if(e.type == SDL_MOUSEBUTTONDOWN)
     {
         if(e.button.button == SDL_BUTTON_LEFT)
         {
             x_val_ += 20;
         }
          else if(e.button.button == SDL_BUTTON_RIGHT)
         {
             x_val_ += 20;
         }
     }
}
void amoObject::handdleMove(const int x_border, const int y_border)
{
    pos.x += 20;
    if(pos.x > x_border)
    {
        is_move = false;
    }
}
int amoObject::getType()
{
    return amoType;
}
void amoObject::setType(int type)
{
    amoType = type;
}
bool amoObject::getIsMove()
{
    return is_move;
}
 void amoObject::setIsMove(bool moveAmo)
 {
     is_move = moveAmo;
 }
 void amoObject::setCurrentFrameAMO(const int width, const int height)
{
            currentFrame.w = width;
            currentFrame.h = height;
}
