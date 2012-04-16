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
        throw ResourceException("FontManager", TTF_GetError());

    addObject(definition, font);

    return font;
}

TextureShared FontManager::createTexture
  (const string& message, const FontDefinition& definition, const SDL_Color& color) {

    FontShared font = getObject(definition);
    SDL_Surface * tempSurface = TTF_RenderText_Blended(font.get(), message.c_str(), color);
    TextureShared tex(SDL_CreateTextureFromSurface(renderer, tempSurface), SDL_DestroyTexture);
    SDL_FreeSurface(tempSurface);
    return tex;

}

