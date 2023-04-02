#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include <list>
#include <chrono>
#include <random>
#include <time.h>
#include <string>

#include "Bird.h"
#include "Barriers.h"
#include "definitions.h"

class Game
{
    public:
        SDL_Texture *tex_numbers[10];

        SDL_Texture *texBackground;
        SDL_Texture *texGround;
        SDL_Texture *texBirdUp;
        SDL_Texture *texBirdMid;
        SDL_Texture *texBirdDown;
        SDL_Texture *texPipe;
        SDL_Texture *texGamedone;

        bool isRunning;

        Game(const char *title, int width, int height);

        void Start();
        void Close();
        void loadTextures();
        void gameDone();
        void update(bool jump, float Timegone, bool &gameover);
        void renderWindow();
        void init();
        void initAudio();

    private:
        SDL_Renderer *renderer;
        SDL_Window *window;

        SDL_Event event;

        Bird *bird;

        Mix_Chunk* jumpSound;
        Mix_Chunk* dieSound;

        std::list<Barrier*> barriers;

        int groundPre, groundNext;

        bool gameBegin, gameover;

};
