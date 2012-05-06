/*
 *  LocationMap.h
 *  Sdl2Test
 *
 *  Created by Max Wittek on 3/30/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef LOCATIONMAP_H_
#define LOCATIONMAP_H_
#include "includes.h"
#include "Tile.h"
#include <vector>
#include "CompositeGameObject.h"

class LocationMap : public CompositeGameObject {

public:
    LocationMap(int rows, int cols, int size);

    // You MUST call init after wrapping LocationMap in a sharedptr.
    void init();
    
    // Get a reference to a tile. Const correctness can s my d.
    TileShared get(int row, int col);
    TileShared getFromPixels(int x, int y);
    
    int getRows();
    int getCols();
    int getSize();
    
    static bool adjacent(const Tile& a, const Tile& b);
    
    virtual bool reactToEvent(const SDL_Event*);
    
private:
    int rows, cols, size;
    std::vector< std::vector<TileShared>> tiles;

    typedef std::vector<std::vector<TileShared>>::iterator RowIter;
    typedef std::vector<TileShared>::iterator ColIter;
};

#endif
