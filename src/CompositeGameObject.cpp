/*
 * CompositeGameObject.cpp
 *
 *  Created on: May 1, 2012
 *      Author: max
 */

#include "CompositeGameObject.h"

CompositeGameObject::CompositeGameObject() :
gameObjects(
  [](GameObjectShared a, GameObjectShared b) {return a->getZ() < b->getZ();}
)
{
    // TODO Auto-generated constructor stub

}

CompositeGameObject::~CompositeGameObject() {
    for(GameObjectShared gameObject : gameObjects)
        gameObject->setParent(0);
}

void CompositeGameObject::paint() {
    for(GameObjectShared gameObject : gameObjects)
        gameObject->paint();
}

void CompositeGameObject::addChild(const GameObjectShared& s) {
    gameObjects.insert(s);
    s->setParent(shared_from_this());
}
