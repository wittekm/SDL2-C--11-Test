/*
 * TextureManager.cpp
 *
 *  Created on: Apr 9, 2012
 *      Author: max
 */

#include "TextureManager.h"
#include "SDL.h"
#include "SDL_image.h"
#include "capp.h"
using std::string;

TextureManager::TextureManager(SDL_Renderer* renderer)
: renderer(renderer)
{ }

TextureShared TextureManager::loadObject(const std::string& filename) {
    // Grab resources
    if(filename.size()<=4)
        throw ResourceException("TextureManager", "Invalid filename, should be _.bmp or _.png");

    string lowerFilename(toLower(filename.substr(filename.size()-4)));
    if(!(lowerFilename == ".bmp" || lowerFilename == ".png"))
        throw ResourceException("TextureManager", "Invalid filename, should be _.bmp or _.png");

    SDL_Surface * tempSurface = IMG_Load(filename.c_str());
    if(!tempSurface)
        throw ResourceException("TextureManager", "Couldn't load texture " + filename);

    // idk what the deal with this palette is...
    if (tempSurface->format->palette)
        SDL_SetColorKey(tempSurface, 1, *(Uint8 *) tempSurface->pixels);

    // Convert to a texture and store it away
    TextureShared tex(
        SDL_CreateTextureFromSurface(renderer, tempSurface),
        SDL_DestroyTexture);

    addObject(filename, tex);

    SDL_FreeSurface(tempSurface);

    return tex;
}
