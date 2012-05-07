#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"

struct Movement {
    float x;
    float y;
};

class Player : public Sprite {
public:
    Player();
    virtual ~Player();

    virtual bool reactToEvent(const SDL_Event*);

    void update();

private:
    Movement movement;
    int speedModifier;
};

#endif
