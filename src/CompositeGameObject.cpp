/*
 * CompositeGameObject.cpp
 *
 *  Created on: May 1, 2012
 *      Author: max
 */

#include "CompositeGameObject.h"

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
    s->setParent(shared_from_this());
}
