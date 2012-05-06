/*
 * CompositeGameObject.cpp
 *
 *  Created on: May 1, 2012
 *      Author: max
 */

#include "CompositeGameObject.h"
#include "SDL.h" // for sdl_event
#include <algorithm>

CompositeGameObject::CompositeGameObject() :
// sorting algorithm: by z-index, then by ptr value (who cares)
gameObjects(
  [](GameObjectShared a, GameObjectShared b) {
    return a->getZ() < b->getZ() ? true : a < b;
  }
)
{ }

CompositeGameObject::~CompositeGameObject() {
    for(GameObjectShared gameObject : gameObjects)
        gameObject->setParent(0);
}

void CompositeGameObject::paint() {
    for(auto& gameObject : gameObjects)
        gameObject->paint();
}

void CompositeGameObject::addChild(const GameObjectShared& s) {
    gameObjects.insert(s);
    try {
        s->setParent(shared_from_this());
    } catch(std::bad_weak_ptr e) {
        debug("You need to wrap this in a SharedPtr first!");
    }
}

bool CompositeGameObject::reactToEvent(const SDL_Event * evt) {
    // Iterates through set until something reacts to event
    auto it = find_if(begin(), end(), 
        [&evt](GameObjectShared go) { return go->reactToEvent(evt); }
    );
    return it == end();
}
