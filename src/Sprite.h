/*
 *  Sprite.h
 *  Sdl2Test
 *
 *  Created by Max Wittek on 4/9/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include "SDL.h"
#include "includes.h"

class Sprite {
public:
    Sprite(const std::string& filename, SDL_Rect rect);

    Sprite(const std::string& filename, int x, int y, int w, int h) :
        Sprite(filename, {x, y, w, h}) { }

    void move(int x, int y);
    void paint();

private:
    SDL_Rect rect;
    TextureShared texture;
};

#endif
