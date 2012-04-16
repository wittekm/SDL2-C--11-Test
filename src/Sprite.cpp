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
#include "SDL.h"
#include "capp.h"

Sprite::Sprite(const std::string& filename)
: rect(), texture()
{
    assert(filename.find("bmp") != string::npos );
    texture = TextureManager::get()->getTexture(filename);
    SDL_QueryTexture(texture.get(), 0, 0, &rect.w, &rect.h); // get width/height
}

Sprite::Sprite(const std::string& filename, SDL_Rect rect)
: rect(rect), texture()
{
    texture = TextureManager::get()->getTexture(filename);
}

void Sprite::move(int x, int y) {
    rect.x = x;
    rect.y = y;
}

void Sprite::paint() {
    SDL_Renderer * renderer = CApp::get()->getRenderer();
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderCopy(renderer, texture.get(), NULL, &rect);
}
