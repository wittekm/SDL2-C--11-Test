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
#include "SdlVideo.h"

#include "LocationMap.h"

#include "TextureManager.h"
#include "FontManager.h"

#include "GameObject.h"
#include "Sprite.h"
#include "Label.h"
#include "CompositeGameObject.h"

using std::dynamic_pointer_cast;
 
CApp::CApp() :
video(SdlVideo::get()),
textureManager(new TextureManager(video->getRenderer())),
fontManager(new FontManager(video->getRenderer())),
running(true),
// sorting algorithm: by z-index, then by ptr value (who cares)
rootObject(new CompositeGameObject()),
player(),
locMap() // can't init here yet!
{ }

// TODO: strip out the window and renderer into something else!
bool CApp::init() {

    // locMap unfortunately requires wrapping in a sharedPtr before init()
    // due to limitations of std::shared_from_this
    locMap.reset(new LocationMap(8, 9, 24));
    locMap->init();
    rootObject->addChild(locMap);

    player.reset(new Sprite("smugman-16.gif"));
    rootObject->addChild(player);

    rootObject->addChild(GameObjectShared(new Label("test guys", "Arial.ttf")));

    debug("Init complete");
    return true;
}
 
int CApp::exec() {
    if(init() == false) {
        return -1;
    }
 
    SDL_Event Event;

    Uint32 oldTime, curTime;
    float deltaTime;
    curTime = SDL_GetTicks();

    while(running) {
        oldTime = curTime;
        curTime = SDL_GetTicks();
        deltaTime = (curTime - oldTime) / 1000.f;

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
    video->setDrawColor(0, 0, 0, 255);
    video->clear();
     
    for(auto& object : *rootObject) {
       object->paint();
    }
 
    // Up until now everything was drawn behind the scenes.
    // This will show the new, red contents of the window.
    video->present();
}

void CApp::onLoop() {
    // Update Player

    
    // Update World

    // Update NPCs
}

void CApp::onEvent(SDL_Event* event) {
    if(event->type == SDL_QUIT)
        running = false;
    if(event->type == SDL_MOUSEBUTTONDOWN) {
        
        // Label movement (for fun!) 
        for(auto& obj : *rootObject) {
            if(LabelShared l = dynamic_pointer_cast<Label>(obj)) {
                l->move({event->button.x, event->button.y});
                debug("hey");
            }
        }

        // Executes reactToEvent on every GameObject.
        rootObject->reactToEvent(event);
    }
}

CApp * CApp::get() {
    static CApp * instance;
    if(!instance)
        instance = new CApp;
    return instance;
}

 
int main(int argc, char* argv[]) {
    CApp * app = CApp::get();
 
    try {
        return app->exec();
    } catch(ResourceException& e) {
        debug(e.what());
    }
    return -1;
}
