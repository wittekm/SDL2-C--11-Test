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
 
#include "SDL.h"
#include "includes.h"
#include "LocationMap.h"

#include <set>
#include <functional>

class TextureManager;
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

    TextureManager * getTextureManager() const {
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
    TextureManager * textureManager;
    FontManager * fontManager;

    // Sort this set by Z-index
    std::set<GameObjectShared, bool(*)(GameObjectShared, GameObjectShared)> gameObjects;

    // Disable copy
    CApp (const CApp&);
    CApp& operator= (const CApp&);
};

 
#endif

