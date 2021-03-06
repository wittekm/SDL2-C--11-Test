/*
 * GameObject.h
 *
 *  Created on: Apr 17, 2012
 *      Author: max
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "SDL.h"
#include "includes.h"
#include <functional>


class GameObject : public std::enable_shared_from_this<GameObject> {
public:
    GameObject(SDL_Rect rect);
    GameObject() : GameObject(SDL_Rect()) { }

    virtual ~GameObject();

    virtual void paint();

    void move(const SDL_Point&);
    void moveDelta(const SDL_Point&);

    void setParent(const GameObjectShared& parent);
    GameObjectShared getParent();

    // Should I do this? Come back later and figure it out.
    //virtual void preDelete(std::function<void(void)> fn) { fn(); }
    virtual void preDelete() { }

    int getZ() { return z; }
    SDL_Rect getRect() { return rect; }

    void setVisible(bool);

protected:
    TextureShared texture;
    SDL_Rect rect;
    SDL_Rect nextRect;
    bool dirty;
    int z;
    bool visible;
    GameObjectWeak parent;
};

#endif /* GAMEOBJECT_H_ */
