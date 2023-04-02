#include <SDL.h>
#include <iostream>

#include "Barriers.h"
#include "definitions.h"

class Bird
{
    public:
        Bird(SDL_Texture *up, SDL_Texture *mid, SDL_Texture *down, SDL_Renderer *renderer);

        void initialize();
        void render();
        void update(bool jump, float Timegone);
        bool collisionChecking(Barrier *pipe);
        void animationEffect();

        int mark;
        bool jump_sound, die_sound;
    private:
        float velocity;
        float acceleration;

        SDL_Rect pos;

        SDL_Texture *up;
        SDL_Texture *down;
        SDL_Texture *mid;
        SDL_Texture *currentTexture;
        SDL_Renderer *renderer;

        int animationFrames;

};
