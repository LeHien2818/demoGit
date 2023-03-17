#pragma once
#include <iostream>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <cstdio>
#include "Entity.hpp"
#include "amoObj.hpp"
#include "game_map.hpp"
using namespace std;

class ThreatObject : public Entity
{
public:
    ThreatObject();
    ThreatObject(Vector2f p_pos, SDL_Texture* p_tex, float in_w, float in_h);

    void setXVal(int val)
    {
        x_val = val;
    }
    void setYVal(int val)
    {
        y_val = val;
    }
    int& getXVal()
    {
        return x_val;
    }
    int& getYVal()
    {
        return y_val;
    }
    void handleMove(const int x_border, const int y_border);
    void handdleInput(SDL_Event e);
    void setAmoList(vector<amoObject*> amo_list);
    vector<amoObject*> getAmoList();
    void initAmo(amoObject* p_amo);
    void makeBullet(const int x_limit, const int y_limit);
    void checkMap(GameMap& inMap);
private:
    int x_val;
    int y_val;

    vector<amoObject*> p_amoList;
};
