#ifndef CHARACTER_HPP_INCLUDED
#define CHARACTER_HPP_INCLUDED
#include <vector>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "amoObj.hpp"
#include "Entity.hpp"
#include "Math.hpp"
#include "game_map.hpp"


using namespace std;


class gameCharacter : public Entity
{
public:
    gameCharacter();
    gameCharacter(Vector2f p_pos, SDL_Texture* p_tex, float w, float h);
    void handdleInputAction(SDL_Event e);
    void handdleMove();
    void checkMap(GameMap& inMap);

    void setAmoList(vector<amoObject*> amo_list);
    vector<amoObject*> getAmoList();
protected:
    float x_val;
    float y_val;

    vector<amoObject*> p_amoList;


};
#endif // CHARACTER_HPP_INCLUDED
