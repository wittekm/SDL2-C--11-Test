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


TextureManager::TextureManager() :
    renderer(CApp::get()->getRenderer())
{

}

TextureManager * TextureManager::get() {
    static TextureManager * manager;
    if(!manager)
        manager = new TextureManager();

    return manager;
}

TextureShared TextureManager::getTexture(const string& filename) {
    auto iter = textureMap.find(filename);
    if(iter == textureMap.end())
        return loadTexture(filename);

    return iter->second;
}

bool TextureManager::hasTexture(const string& filename) {
    auto iter = textureMap.find(filename);
    return iter != textureMap.end();
}

TextureShared TextureManager::loadTexture(const string& filename) {
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

    textureMap.insert(TextureMapPair(filename, tex));

    SDL_FreeSurface(tempSurface);

    return tex;
}
