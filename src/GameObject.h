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

    // Want to spawn an explosion when you die? Now's your chance!
    // virtual void preDelete(std::function<void(void)> fn)
    //   { set predelete function to whatever is passed }
    virtual void preDelete() { }

    int getZ();
    void setZ(int);

    SDL_Rect getRect();

    void setVisible(bool);
    bool getVisible();

    // Return true if this GameObject picked up the event.
    virtual bool reactToEvent(const SDL_Event*);

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
