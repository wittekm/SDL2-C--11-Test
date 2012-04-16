/*
 * Label.h
 *
 *  Created on: Apr 10, 2012
 *      Author: max
 */

#ifndef LABEL_H_
#define LABEL_H_

#include "SDL.h"

#include "includes.h"

class Label : public Paintable {
public:
    Label(const std::string& text, const std::string& font);
    virtual void paint();

private:
    TextureShared texture;
    SDL_Rect rect;
};

#endif /* LABEL_H_ */
