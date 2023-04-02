#include "Game.h"

using namespace std;
Game::Game(const char *title, int width, int height)
{
    srand(time(NULL));

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    loadTextures();

    bird = new Bird(texBirdDown, texBirdMid, texBirdUp, renderer);

    isRunning = true;
    gameover = false;

    groundPre = -WIDTH / 2;
    groundNext = WIDTH / 2;
}

void Game::init()
{
    bird->initialize();
    initAudio();

    for(auto barrier : barriers)
    {
         barriers.pop_front();
    }
    barriers.push_back(new Barrier(WIDTH * 2 + BARRIER_DISTANCE, rand() % 300 + 150));
    barriers.push_back(new Barrier(barriers.back()->bottomDST.x + BARRIER_DISTANCE, rand() % 300 + 150));
    barriers.push_back(new Barrier(barriers.back()->bottomDST.x + BARRIER_DISTANCE, rand() % 300 + 150));

    gameBegin = false;
    gameover = false;

    renderWindow();
}

void Game::Start()
{
    init();
    auto time1 = chrono::system_clock::now();
    auto time2 = time1;

    while(isRunning)
    {
        bool jump = false;
        time1 = time2;
        time2 = chrono::system_clock::now();

        chrono::duration<float> durt = time2 - time1;

        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                isRunning = false;

            if((event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE))
            {
                jump = gameBegin = true;
                Mix_PlayChannel(-1, jumpSound, 0);
            }
        }
        if(frameDelay > durt.count())
           SDL_Delay(frameDelay - durt.count());

        if(gameBegin)
        {
            update(jump, durt.count(), gameover);
            if(gameover)
                gameDone();
        }
    }
    Close();
}

void Game::update(bool jump, float Timegone, bool &gameover)
{
    bird->update(jump, Timegone);

    for(auto barrier : barriers)
    {
        barrier->bottomDST.x -= BARRIER_VELOCITY;
        barrier->topDST.x = barrier->bottomDST.x;

        if(barrier->bottomDST.x + barrier->bottomDST.w < 0)
        {
            barriers.pop_front();
            barriers.push_back(new Barrier(barriers.back()->bottomDST.x + BARRIER_DISTANCE, rand() % 300 + 150));
        }

        if(bird->collisionChecking(barrier))
        {
            Mix_PlayChannel(1, dieSound, 0);
            gameover = true;
        }
    }

    groundPre -= BARRIER_VELOCITY;
    groundNext -= BARRIER_VELOCITY;

    if(groundPre + WIDTH < 0)
        groundPre = WIDTH - 10;
    if(groundNext + WIDTH < 0)
        groundNext = WIDTH - 10;

    renderWindow();
}

void Game::gameDone()
{
    gameBegin = false;

    SDL_RenderCopy(renderer, texGamedone, NULL, new SDL_Rect{WIDTH / 2 - 96, HEIGHT / 3, 192, 42});
    SDL_RenderPresent(renderer);

    //SDL_Delay(1000);

    bool wait = true, playagain = false;
    while(wait)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                wait = false;

            if((event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) || (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT))
                wait = false, playagain = true;
        }
    }

    if(playagain)
        Start();
    else
        isRunning = false;
}

void Game::renderWindow()
{
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, texBackground, NULL, NULL);

    for(auto pipe : barriers)
    {
        pipe->renderPipe(renderer, texPipe);
    }

    SDL_Rect markPosition1;
    markPosition1.x = WIDTH / 2 - 24;
    markPosition1.y = 100;
    markPosition1.w = 40;
    markPosition1.h = 52;
    SDL_Rect markPosition2;
    markPosition2.x = WIDTH / 2 + 24;
    markPosition2.y = 100;
    markPosition2.w = 40;
    markPosition2.h = 52;
    if(bird->mark > 9)
    {
        SDL_RenderCopy(renderer, tex_numbers[bird->mark / 10 % 10], NULL, &markPosition1);
        SDL_RenderCopy(renderer, tex_numbers[bird->mark % 10], NULL, &markPosition2);
    }
    else
        SDL_RenderCopy(renderer, tex_numbers[bird->mark], NULL, new SDL_Rect{WIDTH / 2, 100, 40, 52});

    // ground
    SDL_RenderCopy(renderer, texGround, NULL, new SDL_Rect{groundPre, HEIGHT - GROUND_HEIGHT, WIDTH, GROUND_HEIGHT});
    SDL_RenderCopy(renderer, texGround, NULL, new SDL_Rect{groundNext, HEIGHT - GROUND_HEIGHT, WIDTH, GROUND_HEIGHT});

    // player
    bird->render();

    SDL_RenderPresent(renderer);
}

void Game::loadTextures()
{
    texBackground = IMG_LoadTexture(renderer, "background.png");
    texGround = IMG_LoadTexture(renderer, "ground.png");
    texPipe = IMG_LoadTexture(renderer, "barrier.png");

    texBirdMid = IMG_LoadTexture(renderer, "birdMidflap.png");
    texBirdUp = IMG_LoadTexture(renderer, "birdUpflap.png");
    texBirdDown = IMG_LoadTexture(renderer, "birdDownflap.png");

    texGamedone = IMG_LoadTexture(renderer, "gameDone.png");


    for(int i = 0; i < 10; i++)
    {
        string filepath = "" + to_string(i) + ".png";
        tex_numbers[i] = IMG_LoadTexture(renderer, filepath.c_str());
    }
}

void Game::Close()
{
    IMG_Quit();
    SDL_Quit();
    Mix_Quit();
}
void Game::initAudio()
{
    if(Mix_OpenAudio(4410, MIX_DEFAULT_FORMAT, 2, 1024) < 0)
    {
        cout << "SDL_mixer cannot open file: " << Mix_GetError();
    }
    dieSound = Mix_LoadWAV("die.wav");
    jumpSound = Mix_LoadWAV("wing.wav");
    if(dieSound == NULL )
    {
         cout << "SDL_mixer cannot open file dieSound: " << Mix_GetError();
    }
    if(jumpSound == NULL )
    {
         cout << "SDL_mixer cannot open file jumpSound: " << Mix_GetError();
    }
}

