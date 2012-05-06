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
z(0),
visible(true),
parent()
{ }

GameObject::~GameObject() {
    preDelete();
}

void GameObject::paint() {
    if(!visible) return;
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

void GameObject::setParent(const GameObjectShared& gameObject) {
    parent = gameObject;
}

GameObjectShared GameObject::getParent() {
    return parent.lock();
}

void GameObject::setVisible(bool b) {
    visible = b;
}
bool GameObject::getVisible() { return visible; }

int GameObject::getZ() { return z; }
void GameObject::setZ(int i) { z = i; }

SDL_Rect GameObject::getRect() { return rect; }

bool GameObject::reactToEvent(const SDL_Event* evt) {
    return false;
}
