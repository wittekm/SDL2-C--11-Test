/*
 *  Sprite.cpp
 *  Sdl2Test
 *
 *  Created by Max Wittek on 4/9/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "Sprite.h"
#include "CApp.h"
#include "SDL.h"

TextureManager::TextureManager() {

}

TextureManager * TextureManager::get() {
    static TextureManager * manager;
    if(!manager)
        manager = new TextureManager();
    
    return manager;
}

sharedPtr(SDL_Texture) TextureManager::getTexture(const std::string& filename) {
    auto iter = textureMap.find(filename);
    if(iter == textureMap.end())
        return sharedPtr(SDL_Texture)();
        
    return iter->second;
}

bool TextureManager::hasTexture(const std::string& filename) {
    return getTexture(filename) != NULL;
}

void TextureManager::loadTexture(const std::string& filename) {
    if(hasTexture(filename))
        return;
        
    SDL_Surface * tempSurface = SDL_LoadBMP(filename.c_str());
    if(!tempSurface)
        throw ResourceException("TextureManager", "Couldn't load texture " + filename);
        
    // idk what the deal with this is
    if (tempSurface->format->palette)
        SDL_SetColorKey(tempSurface, 1, *(Uint8 *) tempSurface->pixels);
    
    sharedPtr(SDL_Texture) tex(
        SDL_CreateTextureFromSurface(CApp::get().getRenderer(), tempSurface),
        SDL_DestroyTexture);
     
    textureMap.insert(textureMapPair(filename, tex));
    
    SDL_FreeSurface(tempSurface);
}
