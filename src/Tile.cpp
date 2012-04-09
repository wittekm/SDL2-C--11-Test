/*
 *  Tile.cpp
 *  Sdl2Test
 *
 *  Created by Max Wittek on 4/4/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "Tile.h"

Tile::Tile():
row(-1),
col(-1),
derp(0)
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