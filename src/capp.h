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

class SdlVideo;
class TextureManager;
class FontManager;

class CApp {

// Associated subclasses
public:
    class Time {
    public:
        Time();
        Uint32 oldTime, curTime;
        float deltaTime;
    private:
        void update();
        friend class CApp;
    };

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

    const Time& getTime() const {
        return time;
    }

private:
    SdlVideo * video;

    // Managers
    TextureManager * textureManager;
    FontManager * fontManager;

    Time time;

    bool running;

    // Sort this set by Z-index
    CompositeGameObjectShared rootObject;
    PlayerShared player;
    LocationMapShared locMap;

    // Disable copy
    CApp (const CApp&);
    CApp& operator= (const CApp&);
};

 
#endif

