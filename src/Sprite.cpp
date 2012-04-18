/*
 *  Sprite.cpp
 *  Sdl2Test
 *
 *  Created by Max Wittek on 4/9/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "Sprite.h"
#include "TextureManager.h"
#include "capp.h"

Sprite::Sprite(const std::string& filename)
: GameObject()
{
    // Disallow BMPs with this constructor
    assert(!containsFromEnd(filename, "bmp"));

    texture = CApp::get()->getTextureManager()->getObject(filename);
    SDL_QueryTexture(texture.get(), 0, 0, &nextRect.w, &nextRect.h); // get width/height
}

Sprite::Sprite(const std::string& filename, SDL_Rect rect)
: GameObject(rect)
{
    texture = CApp::get()->getTextureManager()->getObject(filename);
}
