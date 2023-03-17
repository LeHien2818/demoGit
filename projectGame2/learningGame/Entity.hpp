#ifndef ENTITY_HPP_INCLUDED
#define ENTITY_HPP_INCLUDED
#include<cstdio>
#include <iostream>
#include <vector>
#include<SDL.h>
#include <SDL_image.h>
#include "RenderWindow.hpp"
#include "Math.hpp"
#include "MapMatrix.hpp"


class Entity
{
public:
    Entity();
    Entity(Vector2f p_pos, SDL_Texture* p_tex, float in_w, float in_h);
    Vector2f& getPos(){
        return pos;
    }
    void setPos(float x, float y);
    SDL_Rect getCurrentFrame();
    void setCurrentFrame(int width, int height)
    {
        currentFrame.w = width;
        currentFrame.h = height;
    }
    SDL_Texture* getTex();
    void setTex(const char* filePath){
          tex = renderwindow::loadTexture(filePath) ;
    }
    void render(float out_w, float out_h)
    {
        SDL_Rect src;
            src.x = currentFrame.x;
            src.y = currentFrame.y;
            src.h = currentFrame.h;
            src.w = currentFrame.w;
        SDL_Rect dst;
            dst.x = pos.x;
            dst.y = pos.y;
            dst.h = out_h;
            dst.w = out_w ;
        SDL_RenderCopy(renderer, tex, &src, &dst);
    };
    //void handdleInputAction(SDL_Event e);
    //void handdleMove();
protected:
    Vector2f pos;
    SDL_Rect currentFrame;
    SDL_Texture* tex;

};

#endif // ENTITY_HPP_INCLUDED
