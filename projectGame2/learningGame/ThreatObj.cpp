#include "ThreatObj.hpp"

using namespace std;
using namespace renderwindow;

ThreatObject::ThreatObject()
{
    pos.x = WINDOW_WIDTH - 100;
    pos.y = 0;
    currentFrame.w = THREAT_WIDTH;
    currentFrame.h = THREAT_HEIGHT;
    x_val = 0;
    y_val = 0;

}
ThreatObject::ThreatObject(Vector2f p_pos, SDL_Texture* p_tex, float in_w, float in_h)
{
    pos = p_pos;
    tex = p_tex;
    currentFrame.w = in_w;
    currentFrame.h = in_h;
    pos.x = WINDOW_WIDTH - 100;
    pos.y = 0;
    x_val = 0;
    y_val = 0;
}

void ThreatObject::handleMove(const int x_border, const int y_border)
{
    pos.x -= x_val;
    if(pos.x < 0)
    {
        pos.x = 0;
        x_val = 0 - x_val;
        pos.y = rand() % 440;
        if(pos.y > y_border)
        {
            pos.y = y_border * 0.3;
        }
    }if(pos.x > x_border)
    {
        pos.x = x_border;
        x_val = 0 - x_val;
        pos.y = rand() % 440;
        if(pos.y > y_border)
        {
            pos.y = y_border * 0.3;
        }
    }

}
void ThreatObject::handdleInput(SDL_Event e)
{


}
void ThreatObject::setAmoList(vector<amoObject*> amo_list)
{
    p_amoList = amo_list;

}
vector<amoObject*> ThreatObject::getAmoList()
{
    return p_amoList;
}
void ThreatObject::initAmo(amoObject* p_amo)
{
    if(p_amo)
    {
        p_amo->setTex("sphere.png");
        if(p_amo != NULL)
        {
            p_amo->setIsMove(true);
            cout << "EWTF";
            p_amo->setCurrentFrameAMO(WIDTH_SHPERE, HEIGHT_SPHERE);
            p_amo->setType(amoObject::SPHERE);
            p_amo->getPos().x = this->getPos().x + 64;
            p_amo->getPos().y = this->getPos().y + 64;
             p_amoList.push_back(p_amo);
        }
    }
}
void ThreatObject::makeBullet(const int x_limit, const int y_limit)
{
                for(long long unsigned int j = 0; j < p_amoList.size(); j++)
                {
                     amoObject* threat_amo = p_amoList.at(j);
                 if(threat_amo != nullptr)
                 {
                     if(threat_amo->getIsMove())
                     {
                         threat_amo->render(WIDTH_SHPERE, HEIGHT_SPHERE);
                         threat_amo->handdleMove(x_limit, y_limit);
                     }
                     else
                     {
                         if(threat_amo != nullptr )
                         {
                             p_amoList.erase(p_amoList.begin() + j);
                             this->setAmoList(p_amoList);
                             delete threat_amo;
                             threat_amo = nullptr;
                         }
                     }
                 }
             }
}

void ThreatObject::checkMap(GameMap& inMap)
 {
    int x1 = 0;
    int x2 = 0;

    int y1 = 0;
    int y2 = 0;

    x1 = (pos.x + x_val)/TILE_SIZE;
    x2 = (pos.x + x_val + 74)/TILE_SIZE;

    y1= (pos.y )/TILE_SIZE;
    y2 = (pos.y + 110)/TILE_SIZE;

    if(x1 >= 0 && x2 < MAP_MAX_X && y1 >= 0 && y2 < MAP_MAX_Y )
    {
        if(x_val > 0) // moving right
        {
            if(inMap.getGame_Map().tile[y1][x2] != 0 || inMap.getGame_Map().tile[y2][x2] != 0)
            {
                //pos.x = x2*TILE_SIZE;
                //pos.x -= 74 + 1;
                x_val = 0 - x_val;
            }
        }
        else if(x_val < 0)
        {
            if(inMap.getGame_Map().tile[y1][x1] != 0 || inMap.getGame_Map().tile[y2][x1] != 0)
            {
                //pos.x = (x1 + 1)*TILE_SIZE - 32;
                x_val = 0 - x_val;
            }
        }
    }


    x1 = (pos.x )/TILE_SIZE;
    x2 = (pos.x + 74)/TILE_SIZE;

    y1= (pos.y + y_val)/TILE_SIZE;
    y2 = (pos.y + y_val + 110)/TILE_SIZE;
    if(x1 >= 0 && x2 < MAP_MAX_X && y1 >= 0 && y2 < MAP_MAX_Y )
    {
        if(y_val > 0) // moving right
        {
            if(inMap.getGame_Map().tile[y2][x1] != 0 || inMap.getGame_Map().tile[y2][x2] != 0)
            {
                //pos.y = y2*TILE_SIZE;
                //pos.y -= 120 + 1;
                y_val = 0 - y_val;
            }
        }
        else if(y_val < 0) // moving right
        {
            if(inMap.getGame_Map().tile[y1][x1] != 0 || inMap.getGame_Map().tile[y1][x2] != 0)
            {
                //pos.y = (y1 + 1)*TILE_SIZE;
                y_val = 0 - y_val;
            }
        }
    }

 }
