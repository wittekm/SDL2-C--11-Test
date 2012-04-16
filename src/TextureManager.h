/*
 * TextureManager.h
 *
 *  Created on: Apr 9, 2012
 *      Author: max
 */

#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_

#include "Manager.h"
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

class TextureManagerTwo : public Manager<std::string, TextureShared> {
    public:
        TextureManagerTwo(SDL_Renderer* renderer);

    private:
        virtual TextureShared loadObject(const std::string&);

        SDL_Renderer* renderer;
};


#endif /* TEXTUREMANAGER_H_ */
