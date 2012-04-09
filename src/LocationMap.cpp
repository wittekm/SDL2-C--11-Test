/*
 *  LocationMap.cpp
 *  Sdl2Test
 *
 *  Created by Max Wittek on 3/30/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "LocationMap.h"
#include "Settings.h"
#include <stdexcept>
#include <algorithm>
#include <functional>

using std::vector;

class LocationBoundsException : std::exception { };

//for_each(agentInfos.begin(), agentInfos.end(), bind(&Game::addAgentInfo, this, _1));


LocationMap::LocationMap(int rows, int cols, int size):
    rows(rows), 
    cols(cols), 
    size(size),
    tiles(rows, std::vector<sharedPtr(Tile)>(cols))
{
    if(!(rows > 0 && cols > 0 && size > 0))
        throw std::invalid_argument("LocationMap initialization: rows, cols, size must be > 0.");
    initTiles();
}

void LocationMap::initTiles() {
    bool hi = false;

    auto text = std::string("hey");

    for(vector<sharedPtr(Tile)>& col : tiles) {
        for(sharedPtr(Tile)& tile : col) {
            tile.reset(new Tile());
            hi = !hi;
            tile->setDerp(hi);
        }
    }

}

weakPtr(Tile) LocationMap::get(int row, int col) {
    if(row < 0 || col < 0 || row >= rows || col >= cols)
        throw LocationBoundsException();

    return weakPtr(Tile)(tiles.at(row).at(col));
}

weakPtr(Tile) LocationMap::getFromPixels(int x, int y) {
    /*
    x /= Settings::get().devicePixelRatio;
    y /= Settings::get().devicePixelRatio;
    */
    x /= size;
    y /= size;
    
    return get(x, y);
}

int LocationMap::getRows() { return rows; }

int LocationMap::getCols() { return cols; }

int LocationMap::getSize() { return size; }

static bool adjacent(const Tile& a, const Tile& b) {
    int rowDiff = abs(a.getRow() - b.getRow());
    int colDiff = abs(a.getCol() - b.getCol());
    return (rowDiff <= 1) && (colDiff <= 1) && (rowDiff != colDiff);
}

//template class LocationMap<Tile>;

