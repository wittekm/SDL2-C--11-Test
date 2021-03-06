/*
 *  Tile.h
 *  Sdl2Test
 *
 *  Created by Max Wittek on 4/4/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef TILE_H_
#define TILE_H_

#include "includes.h"

class Tile {
    public:
        Tile();
        int getRow() const;
        int getCol() const;
        void setDerp(const int& d);
        int getDerp();
        SpriteShared getSprite();
        void setSprite(const SpriteShared&);
        
    private:
        int row, col;
        int derp;
        SpriteShared sprite;
};

#endif
