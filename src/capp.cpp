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
map(8, 9, 24),
// sorting algorithm: by z-index, then by ptr value (who cares)
rootObject(new CompositeGameObject())
{ }

// TODO: strip out the window and renderer into something else!
bool CApp::init() {
    // Can't do these in initlist; need renderer

    //gameObjects.insert(GameObjectShared(new Sprite("icon.bmp", {20, 20, 32, 32})));
    rootObject->addChild(GameObjectShared(new Sprite("smugman-16.gif")));

    rootObject->addChild(GameObjectShared(new Label("test this is srsly a test u guys", "Arial.ttf")));

    for(int i = 0; i < map.getRows(); i++) {
        for(int j = 0; j < map.getCols(); j++) {
            TileShared t = map.get(i, j).lock();

            auto sprite = SpriteShared(new Sprite("smugman-16.gif"));
            t->setSprite(sprite);
            sprite->move({i * map.getSize(), j * map.getSize()});
            rootObject->addChild(sprite);

            sprite->setVisible(t->getDerp());
        }
    }

    return true;
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
    video->setDrawColor(0, 0, 0, 255);
    video->clear();
    
    video->setDrawColor(0, 255, 255, 255);
    SDL_Rect rect;
    rect.w = map.getSize();
    rect.h = map.getSize();
    
    
    debug("here");
     
    for(auto& g : *rootObject) {
       g->paint();
    }
    
 
    // Up until now everything was drawn behind the scenes.
    // This will show the new, red contents of the window.
    video->present();
}

void CApp::onLoop() {
}

void CApp::onEvent(SDL_Event* event) {
    if(event->type == SDL_QUIT)
        running = false;
    if(event->type == SDL_MOUSEBUTTONDOWN) {
        TileShared t = map.getFromPixels(event->button.x, event->button.y).lock();
        t->setDerp(!t->getDerp());
        t->getSprite()->setVisible(t->getDerp());

        for(auto& g : *rootObject) {
            debug("event");
            if(LabelShared l = dynamic_pointer_cast<Label>(g)) {
                l->move({event->button.x, event->button.y});
                debug("hey");
            }
        }
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
/*
bool CApp::GameObjectZCompare::operator()(GameObjectShared a, GameObjectShared b) {
    return a->getZ() < b->getZ();
};
*/
