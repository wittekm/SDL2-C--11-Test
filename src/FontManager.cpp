/*
 * FontManager.cpp
 *
 *  Created on: Apr 12, 2012
 *      Author: max
 */

#include "FontManager.h"
#include "SDL_ttf.h"
using std::string;

FontManager::FontManager(SDL_Renderer* renderer)
: renderer(renderer)
{ }

FontShared FontManager::loadObject(const FontDefinition& definition) {
    // Create shared pointer that cleans up with TTF_CloseFont
    FontShared font(TTF_OpenFont(definition.fontFamily.c_str(), definition.size), TTF_CloseFont);
    if(!font)
        throw ResourceException("FontManager", "Could not create font");

    //addObject(definition, font);

    return font;
}

TextureShared createTexture(const string& message, const FontDefinition& definition) {
    SDL_Surface * tempSurface = TTF_RenderText_Solid( font, "quick brown fox", textColor );
    return TextureShared(
            SDL_CreateTextureFromSurface(renderer, tempSurface),
            SDL_DestroyTexture);
}

