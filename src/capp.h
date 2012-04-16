/*
 *  capp.h
 *  Sdl2Test
 *
 *  Created by Max Wittek on 3/29/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
 
#ifndef CAPP_H_
#define CAPP_H_
 
#include <SDL.h>
#include "includes.h"
#include "LocationMap.h"
#include "Sprite.h"
#include "Label.h"

class TextureManagerTwo;
class FontManager;

class CApp {

public:
    CApp();
    
    SDL_Renderer * getRenderer();

    int exec();

public:
    bool init();
    void onEvent(SDL_Event* Event);
    void onLoop();
    void render();
    void clean();

    static CApp * get();

    TextureManagerTwo * getTextureManager() const {
        assert(textureManager);
        return textureManager;
    }

    FontManager * getFontManager() const {
        assert(fontManager);
        return fontManager;
    }

private:
    LocationMap map;
    bool running;
    SDL_Window * window;
    SDL_Renderer * renderer;

    // Managers
    TextureManagerTwo * textureManager;
    FontManager * fontManager;

    Sprite * s;
    Label * label;

    // Disable copy
    CApp (const CApp&);
    CApp& operator= (const CApp&);
};

 
#endif

