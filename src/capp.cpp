/*
 *  capp.cpp
 *  Sdl2Test
 *
 *  Created by Max Wittek on 3/29/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "capp.h"
#include "libwittek.h"
#include "LocationMap.h"
#include "Sprite.h"
 
CApp::CApp() :
map(8, 9, 24) {
    running = true;
}
 
int CApp::exec() {
    if(init() == false) {
        return -1;
    }
 
    SDL_Event Event;
 
    while(running) {
        while(SDL_PollEvent(&Event)) {
            onEvent(&Event);
        }
 
        onLoop();
        render();
        SDL_Delay(200);
    }
 
    clean();
 
    return 0;
}

void CApp::clean() {
    SDL_Quit();
}


void CApp::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    SDL_Rect rect;
    rect.w = map.getSize();
    rect.h = map.getSize();
    
    for(int i = 0; i < map.getRows(); i++) {
        for(int j = 0; j < map.getCols(); j++) {
            sharedPtr(Tile) t = map.get(i, j).lock();
            if(t->getDerp()) {
                rect.x = i * map.getSize();
                rect.y = j * map.getSize();
                SDL_RenderDrawRect(renderer, &rect);
            }
        }
    }
    
    SDL_Rect drawRect;
    drawRect.x = 20;
    drawRect.y = 20;
    drawRect.w = 16;
    drawRect.h = 16;
    SDL_RenderFillRect(renderer, &drawRect);
    SDL_RenderCopy(renderer, texture.get(), NULL, &drawRect);

    // Up until now everything was drawn behind the scenes.
    // This will show the new, red contents of the window.
    SDL_RenderPresent(renderer);
}

void CApp::onLoop() {
}

void CApp::onEvent(SDL_Event* event) {
    if(event->type == SDL_QUIT)
        running = false;
    if(event->type == SDL_MOUSEBUTTONDOWN) {
        sharedPtr(Tile) t = map.getFromPixels(event->button.x, event->button.y).lock();
        t->setDerp(!t->getDerp());
    }
}

bool CApp::init() {
    
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return false;
        
    window = SDL_CreateWindow("SDL_RenderClear",
                SDL_WINDOWPOS_CENTERED, 
                SDL_WINDOWPOS_CENTERED,
                256, 256,
                SDL_WINDOW_SHOWN);
                
    renderer = SDL_CreateRenderer(window, -1, 0);
    
    debug("-----");
    debug(TextureManager::get()->hasTexture("icon.bmp"));
    TextureManager::get()->loadTexture("icon.bmp");
    texture = TextureManager::get()->getTexture("icon.bmp");
    debug(TextureManager::get()->hasTexture("icon.bmp"));
    debug("-----");

    return true;
}

CApp& CApp::get() {
    static CApp * instance;
    if(!instance)
        instance = new CApp;
    return *instance;
}

SDL_Renderer * CApp::getRenderer() {
    return renderer;
}

 
int main(int argc, char* argv[]) {
    CApp& app = CApp::get();
    
    debug("hey");
 
    return app.exec();
}
