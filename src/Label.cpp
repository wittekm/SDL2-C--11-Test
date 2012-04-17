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

Label::Label(const string& text, const string& font) :
GameObject()
{
    static FontManager * fontManager = CApp::get()->getFontManager();
    texture = fontManager->createTexture(text, {font, 12});
    SDL_QueryTexture(texture.get(), 0, 0, &nextRect.w, &nextRect.h); // get width/height
}
