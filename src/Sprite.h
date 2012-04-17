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

#include "GameObject.h"

class Sprite : public GameObject {
public:
    Sprite(const std::string& filename); // Don't use with BMP!

    Sprite(const std::string& filename, SDL_Rect rect);
};

#endif
