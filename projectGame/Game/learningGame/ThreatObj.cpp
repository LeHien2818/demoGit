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
        pos.x = WINDOW_WIDTH;
        pos.y = rand() % 440;
        if(pos.y > WINDOW_HEIGHT)
        {
            pos.y = WINDOW_HEIGHT * 0.3;
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
            p_amo->setCurrentFrameAMO(WIDTH_SHPERE, HEIGHT_SPHERE);
            p_amoList.push_back(p_amo);
            p_amo->setType(amoObject::SPHERE);
        }
    }
}
