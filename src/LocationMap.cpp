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
#include <functional>
#include <algorithm>
#include "Sprite.h"
#include "SDL.h" // for sdl_event

using std::vector;
using std::for_each;

class LocationBoundsException : std::exception { };

//for_each(agentInfos.begin(), agentInfos.end(), bind(&Game::addAgentInfo, this, _1));


LocationMap::LocationMap(int rows, int cols, int size):
    CompositeGameObject(),
    rows(rows), 
    cols(cols), 
    size(size),
    tiles(rows, std::vector<TileShared>(cols)) 
{
    if(!(rows > 0 && cols > 0 && size > 0))
        throw std::invalid_argument("LocationMap initialization: rows, cols, size must be > 0.");
}

void LocationMap::init() {
    bool hi = false;

    for_each(tiles.begin(), tiles.end(), [&hi,this](vector<TileShared>& col) {
        for_each(col.begin(), col.end(), [&hi,this](TileShared& tile) {
            // Closures. Neat! hi is fed in as a reference.
            tile.reset(new Tile());
            hi = !hi;
            tile->setDerp(hi);

            auto sprite = SpriteShared(new Sprite("smugman-16.gif"));
            sprite->setVisible(tile->getDerp());
            addChild(sprite);
            tile->setSprite(sprite);
        } );
    } );

    // Using i/j instead of range-based to moving sprite
    debug("hey");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            TileShared& t = tiles.at(i).at(j);
            t->getSprite()->move({i*size, j*size});
        }
    }
    debug("ok");

}

TileShared LocationMap::get(int row, int col) {
    if(row < 0 || col < 0 || row >= rows || col >= cols)
        throw LocationBoundsException();

    return tiles.at(row).at(col);
}

TileShared LocationMap::getFromPixels(int x, int y) {
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

/*
static bool adjacent(const Tile& a, const Tile& b) {
    int rowDiff = abs(a.getRow() - b.getRow());
    int colDiff = abs(a.getCol() - b.getCol());
    return (rowDiff <= 1) && (colDiff <= 1) && (rowDiff != colDiff);
}
*/

bool LocationMap::reactToEvent(const SDL_Event * evt) {
    // Tiles don't react to events so don't bother iterating them.
    try {
        TileShared t = getFromPixels(evt->button.x, evt->button.y);
        t->setDerp(!t->getDerp());
        t->getSprite()->setVisible(t->getDerp());
        return true;
    } catch(LocationBoundsException e) { }

    return false;
} 
