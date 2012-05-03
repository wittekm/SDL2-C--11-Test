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
public:
    CompositeGameObject();
    virtual ~CompositeGameObject();
    void addChild(const GameObjectShared& gameObject);
    virtual void paint();
private:
    typedef std::function<bool(GameObjectShared, GameObjectShared)> GameObjectSharedComparator;
    std::set<GameObjectShared, GameObjectSharedComparator> gameObjects;
};

#endif /* COMPOSITEGAMEOBJECT_H_ */
