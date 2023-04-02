#include "Bird.h"

void Bird::initialize()
{
    jump_sound = false, die_sound = false;
    currentTexture = mid;
    animationFrames = 0;
    mark = 0;

    velocity = 0.0f;
    acceleration = 0.0f;

    pos.x = WIDTH / 3 - 32;
    pos.y = HEIGHT / 2;
    pos.w = BIRD_WIDTH;
    pos.h = BIRD_HEIGHT;
}

Bird::Bird(SDL_Texture *up, SDL_Texture *mid, SDL_Texture *down, SDL_Renderer *renderer)
 : up(up), mid(mid), down(down), renderer(renderer)
{
    initialize();
}

void Bird::update(bool jump, float Timegone)
{
    Timegone *= 5;
    if(jump)
    {
        acceleration = 0.0f;
        velocity = -GRAVITY;
    }
    else
    {
        acceleration += GRAVITY * Timegone;
    }

    if(acceleration >= GRAVITY)
        acceleration = GRAVITY;

    velocity += acceleration * Timegone;
    pos.y += velocity * Timegone;
}

bool Bird::collisionChecking(Barrier *pipe)
{
    // pipe
    if(pipe->topDST.x <= pos.x + pos.w && pipe->topDST.x + BARRIER_WIDTH >= pos.x + pos.w)
        if(pos.y < pipe->topDST.y + pipe->topDST.h || pos.y + pos.h > pipe->bottomDST.y)
        {
            return true;
            die_sound = true;
        }
    // ground
    if(pos.y + pos.h > HEIGHT - GROUND_HEIGHT)
    {
        return true;
        die_sound = true;
    }

    // ceiling
    if(pos.y < 0)
    {
        return true;
        die_sound = true;
    }

    if(!pipe->passed && pipe->topDST.x + BARRIER_WIDTH < pos.x)
    {
        pipe->passed = true;
        mark++;
    }

    return false;
}

void Bird::render()
{
    animationEffect();

    if(velocity == 0)
        SDL_RenderCopy(renderer, mid, NULL, &pos);
    else if(velocity < 50)
        SDL_RenderCopyEx(renderer, currentTexture, NULL, &pos, -30.0, NULL, SDL_FLIP_NONE);
    else if(velocity >= 50 && velocity < 200)
        SDL_RenderCopyEx(renderer, currentTexture, NULL, &pos, 30.0, NULL, SDL_FLIP_NONE);
    else if(velocity >= 200)
        SDL_RenderCopyEx(renderer, mid, NULL, &pos, 90.0, NULL, SDL_FLIP_NONE);

}

void Bird::animationEffect()
{
    animationFrames++;

    if(animationFrames == 5)
        currentTexture = down;
    else if(animationFrames == 15)
        currentTexture= mid;
    else if(animationFrames == 20)
    {
        animationFrames = 0;
        currentTexture = up;
    }
}
