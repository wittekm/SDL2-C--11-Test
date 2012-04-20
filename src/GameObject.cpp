/*
 * GameObject.cpp
 *
 *  Created on: Apr 17, 2012
 *      Author: max
 */

#include "GameObject.h"
#include "SdlVideo.h"

GameObject::GameObject(SDL_Rect rect) :
texture(),
rect(rect),
nextRect(),
dirty(true),
z(0)
{ }

GameObject::~GameObject() {
    preDelete();
}

void GameObject::paint() {
    //if(!dirty) return;
    rect = nextRect;
    static SdlVideo * video = SdlVideo::get();
    video->copy(texture.get(), rect);
    dirty = false;
}

void GameObject::move(const SDL_Point& p) {
    nextRect.x = p.x;
    nextRect.y = p.y;
    dirty = true;
}

void GameObject::moveDelta(const SDL_Point& p) {
    nextRect.x += p.x;
    nextRect.y += p.y;
    dirty = true;
}
