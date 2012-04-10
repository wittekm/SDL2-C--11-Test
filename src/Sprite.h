/*
 *  Sprite.h
 *  Sdl2Test
 *
 *  Created by Max Wittek on 4/9/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "SDL.h"
#include "includes.h"

class Sprite {
public:
    Sprite(const std::string& filename, int x, int y, int w, int h);
    Sprite(const std::string& filename, SDL_Rect rect);

    void move(int x, int y);
    void paint();

private:
    void init(const std::string&, SDL_Rect);
    SDL_Rect rect;
    sharedPtr(SDL_Texture) texture;
};

#endif
