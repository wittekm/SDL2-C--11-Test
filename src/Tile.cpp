/*
 *  Tile.cpp
 *  Sdl2Test
 *
 *  Created by Max Wittek on 4/4/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "Tile.h"
#include "Sprite.h"

Tile::Tile():
row(-1),
col(-1),
derp(0),
sprite(/*new Sprite("smugman-16.gif")*/)
{

}

int Tile::getRow() const {
    return row;
}

int Tile::getCol() const {
    return col;
}

void Tile::setDerp(const int& d) {
    derp = d;
}

int Tile::getDerp() { return derp; }

SpriteShared Tile::getSprite() { return sprite; }
void Tile::setSprite(const SpriteShared& s) { sprite = s; }
