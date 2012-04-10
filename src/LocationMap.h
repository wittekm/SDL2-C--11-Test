/*
 *  LocationMap.h
 *  Sdl2Test
 *
 *  Created by Max Wittek on 3/30/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _LOCATIONMAP_H_
#define _LOCATIONMAP_H_
#include "includes.h"
#include "Tile.h"
#include <vector>


class LocationMap {

public:
    LocationMap(int rows, int cols, int size);
    void initTiles();
    
    // Get a reference to a tile. Const correctness can s my d.
    TileWeak get(int row, int col);
    TileWeak getFromPixels(int x, int y);
    
    
    int getRows();
    int getCols();
    int getSize();
    
    static bool adjacent(const Tile& a, const Tile& b);
    
    
private:
    int rows, cols, size;
    std::vector< std::vector<TileShared>> tiles;
    
    typedef std::vector<std::vector<TileShared>>::iterator RowIter;
    typedef std::vector<TileShared>::iterator ColIter;
};

#endif
