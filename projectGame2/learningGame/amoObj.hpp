#ifndef AMOOBJ_HPP_INCLUDED
#define AMOOBJ_HPP_INCLUDED
#include <iostream>
#include <vector>
#include <SDL.h>
#include "Entity.hpp"

using namespace std;

class amoObject : public Entity
{
public:
    enum AmoType
    {
        NONE = 0,
        LASER = 1,
        SPHERE = 2
    };
    amoObject();
    amoObject(Vector2f p_pos, SDL_Texture* p_tex, float in_w, float in_h);
    void handdleInput(SDL_Event e);
    void handdleMove(const int x_border, const int y_border);

    int getType();
    void setType(int type);
    bool getIsMove();
    void setIsMove(bool moveAmo);
    void setCurrentFrameAMO(const int width, const int height);

protected:
    float x_val_, y_val_;
    bool is_move;
    int amoType;

};
#endif // AMOOBJ_HPP_INCLUDED
