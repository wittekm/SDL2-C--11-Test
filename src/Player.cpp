#include "Player.h"
#include "SDL.h" // for SDLKey

Player::Player() :
    Sprite("smugman-16.gif"),
    movement({0,0}),
    speedModifier(1)
{

}

Player::~Player() { }

bool Player::reactToEvent(const SDL_Event* event) {
    //static int moveKeys[] = {SDLK_W, SDLK_A, SDLK_S, SDLK_D};
    
    if(event->type == SDL_KEYDOWN) {
        switch( event->key.keysym.sym ) { 
            case SDLK_DOWN: movement  = {0,1};   return true; break;
            case SDLK_UP: movement    = {0,-1};  return true; break;
            case SDLK_LEFT: movement  = {-1,0};  return true; break;
            case SDLK_RIGHT: movement = {1,0};   return true; break;
            case SDLK_LSHIFT: speedModifier = 5; return true; break;
        }
    }
    else if(event->type == SDL_KEYUP) {
        int key = event->key.keysym.sym;
        //if( std::find(keyArray, keyArray+4, keysym) )
        if(key >= SDLK_RIGHT && key <= SDLK_UP)
            movement = {0,0};
        else
            speedModifier = 1; 
    }
    return false;
}

void Player::update() {
    moveDelta({movement.x * speedModifier, movement.y * speedModifier});
}
