/*
 *  Sprite.h
 *  Sdl2Test
 *
 *  Created by Max Wittek on 4/9/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "includes.h"
#include <map>

class Sprite {

};

class TextureManager {
    protected:
        // only TexManager can instantiate it, so proctected
        TextureManager();
    public:
        static TextureManager * get();
        
        // these could be statics if I wanted to, but I prefer get()->
        sharedPtr(SDL_Texture) getTexture(const std::string&);
        bool hasTexture(const std::string&);
        void loadTexture(const std::string& filename);

    private:
        std::map<std::string, sharedPtr(SDL_Texture)> textureMap;
        typedef std::map<std::string, sharedPtr(SDL_Texture)>::iterator textureMapIterator;
        typedef std::pair<std::string, sharedPtr(SDL_Texture)> textureMapPair;
};



#endif
