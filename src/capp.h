/*
 *  capp.h
 *  Sdl2Test
 *
 *  Created by Max Wittek on 3/29/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
 
#ifndef _CAPP_H_
#define _CAPP_H_
 
#include <SDL.h>
#include "includes.h"
#include "LocationMap.h"
#include "Sprite.h"
 
class CApp {

private:
    LocationMap map;
    bool running;
    SDL_Window * window;
    SDL_Renderer * renderer;
    
    Sprite * s;

    // Disable copy
    CApp (const CApp&);
    CApp& operator= (const CApp&);

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

};

 
#endif

