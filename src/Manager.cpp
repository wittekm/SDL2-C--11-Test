/*
 * Manager.cpp
 *
 *  Created on: Apr 12, 2012
 *      Author: max
 */

#ifndef MANAGER_CPP
#define MANAGER_CPP

#include "Manager.h" // Superfluous, but whatever

#include "SDL.h"
#include "SDL_image.h"
#include "capp.h"
using std::string;

template <class Key, class SharedPtr>
Manager<Key, SharedPtr>::Manager() { }

template <class Key, class SharedPtr>
SharedPtr Manager<Key, SharedPtr>::getObject(const Key& key) {
    auto iter = objectMap.find(key);
    if(iter == objectMap.end())
        return loadObject(key);

    return iter->second;
}

template <class Key, class SharedPtr>
bool Manager<Key, SharedPtr>::hasObject(const Key& key) {
    auto iter = objectMap.find(key);
    return iter != objectMap.end();
}

template <class Key, class SharedPtr>
void Manager<Key, SharedPtr>::addObject(const Key& key, const SharedPtr& ptr) {
    objectMap.insert(MapPair(key, ptr));
}


#endif
