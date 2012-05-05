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

class TextureManager : public Manager<std::string, TextureShared> {
    public:
        TextureManager(SDL_Renderer* renderer);

    private:
        virtual TextureShared loadObject(const std::string&);
        SDL_Renderer* renderer;
};


#endif /* TEXTUREMANAGER_H_ */
