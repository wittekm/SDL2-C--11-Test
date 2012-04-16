/*
 * FontManager.h
 *
 *  Created on: Apr 12, 2012
 *      Author: max
 */

#ifndef FONTMANAGER_H_
#define FONTMANAGER_H_

#include "includes.h"
#include "Manager.h"

struct FontDefinition {
    std::string fontFamily;
    int size;

    bool operator<( const FontDefinition & other ) const {
      // Pretty sure this is right, but check it.
      return fontFamily < other.fontFamily ? true :
              size < other.size;
    }
};

class FontManager : public Manager<FontDefinition, FontShared> {
    public:
        FontManager(SDL_Renderer* renderer);
        TextureShared createTexture(const std::string&, const FontDefinition&, const SDL_Color& = {127,127,127});

    private:
        FontShared loadObject(const FontDefinition&);
        SDL_Renderer * renderer;
};

#endif
