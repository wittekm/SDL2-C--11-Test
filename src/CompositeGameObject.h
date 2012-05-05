/*
 * CompositeGameObject.h
 *
 *  Created on: May 1, 2012
 *      Author: max
 */

#ifndef COMPOSITEGAMEOBJECT_H_
#define COMPOSITEGAMEOBJECT_H_
#include "GameObject.h"
#include "includes.h"
#include <set>
#include <functional>

class CompositeGameObject : public GameObject {
private:
     typedef std::function<bool(GameObjectShared, GameObjectShared)> GameObjectSharedComparator;
     typedef std::set<GameObjectShared, GameObjectSharedComparator> GameObjectsSet;
public:
    CompositeGameObject();
    virtual ~CompositeGameObject();
    void addChild(const GameObjectShared& gameObject);
    virtual void paint();
    
    GameObjectsSet::iterator begin() { return gameObjects.begin(); }
    GameObjectsSet::iterator end() { return gameObjects.end(); }

private:
    GameObjectsSet gameObjects;
};

#endif /* COMPOSITEGAMEOBJECT_H_ */
