/*
 *  includes.h
 *  Sdl2Test
 *
 *  Created by Max Wittek on 3/30/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
 
 
#ifndef _INCLUDES_H_
#define _INCLUDES_H_

#define sharedPtrTypedef(type) typedef std::shared_ptr< type > type ## Shared
// #define sharedPtr(type) std::tr1::shared_ptr< type >
#define weakPtrTypedef(type) typedef std::weak_ptr< type > type ## Weak
//#define weakPtr(type) std::tr1::weak_ptr< type >

#include "libwittek.h"
#include <string>
#include <tr1/memory>
#include <memory>

// forward declarations
class CApp;
class Tile;

class SDL_Window;
class SDL_Renderer;
class SDL_Texture;
class SDL_Surface;

/*
sharedPtrTypedef(Tile);
sharedPtrTypedef(SDL_Window);
*/


typedef std::shared_ptr< SDL_Texture > TextureShared;
typedef std::weak_ptr< SDL_Texture > TextureWeak;

typedef std::shared_ptr< Tile > TileShared;
typedef std::weak_ptr< Tile > TileWeak;

#endif
