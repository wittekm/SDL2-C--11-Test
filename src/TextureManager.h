/*
 * TextureManager.h
 *
 *  Created on: Apr 9, 2012
 *      Author: max
 */

#ifndef _TEXTUREMANAGER_H_
#define _TEXTUREMANAGER_H_

#include "includes.h"
#include <map>

class TextureManager {
    protected:
        // only TexManager can instantiate it, so proctected
        TextureManager();
    public:
        static TextureManager * get();

        // these could be statics if I wanted to, but I prefer get()->
        TextureShared getTexture(const std::string&);
        bool hasTexture(const std::string&);

    private:
        TextureShared loadTexture(const std::string& filename);
        std::map<std::string, TextureShared> textureMap;
        SDL_Renderer * renderer;

        typedef std::pair<std::string, TextureShared> TextureMapPair;
};

#endif /* TEXTUREMANAGER_H_ */
