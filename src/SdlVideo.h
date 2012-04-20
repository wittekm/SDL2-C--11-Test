/*
 * SdlVideo.h
 *
 *  Created on: Apr 20, 2012
 *      Author: max
 */

#ifndef SDLVIDEO_H_
#define SDLVIDEO_H_

#include "includes.h"

// Exception thrown if there's an SDL error
class SdlVideoException : public std::runtime_error {
public:
    SdlVideoException(const std::string& s);
    static SdlVideoException sdlGetError();
};

// Singleton containing SDL video stuff
class SdlVideo : public Singleton<SdlVideo> {
public:
    SDL_Renderer * getRenderer() { return renderer; }
    SDL_Window * getWindow() { return window; }
    void copy(SDL_Texture *, const SDL_Rect& dest);
    void copy(SDL_Texture *, const SDL_Rect* src, const SDL_Rect* dest);
    void clear();
    void present();
    void setDrawColor(int, int, int, int);
    void drawRect(const SDL_Rect& rect);


protected:
    SdlVideo();
    virtual ~SdlVideo();

    // throws exceptions if need be
    static void sdlCall(int);

private:
    SDL_Window * window;
    SDL_Renderer * renderer;

// Allow singleton template to initialize
friend class Singleton<SdlVideo>;
};


#endif /* SDLVIDEO_H_ */
