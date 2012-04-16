/*
 * Label.cpp
 *
 *  Created on: Apr 10, 2012
 *      Author: max
 */

#include "Label.h"
#include "capp.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include "FontManager.h"

using std::string;

Label::Label(const string& text, const string& font) {
    // TODO Auto-generated constructor stub
    texture = CApp::get()->getFontManager()->createTexture(text, {font, 12});
    SDL_QueryTexture(texture.get(), 0, 0, &rect.w, &rect.h); // get width/height
}

void Label::paint() {
    SDL_Renderer * renderer = CApp::get()->getRenderer();
    SDL_RenderCopy(renderer, texture.get(), NULL, &rect);
}
