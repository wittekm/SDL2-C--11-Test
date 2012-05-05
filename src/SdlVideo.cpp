/*
 * SdlVideo.cpp
 *
 *  Created on: Apr 20, 2012
 *      Author: max
 */

#include "SdlVideo.h"
#include "SDL_ttf.h"

SdlVideoException::SdlVideoException(const std::string& s) :
std::runtime_error(s)
{ }

SdlVideoException SdlVideoException::sdlGetError() {
    return SdlVideoException(SDL_GetError());
}

SdlVideo::SdlVideo() :
window(0),
renderer(0)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
        throw SdlVideoException("SDL Init Failed");

    if(TTF_Init()==-1) {
        throw SdlVideoException(TTF_GetError());
    }

    window = SDL_CreateWindow("sdl is dumb",
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                256, 256,
                SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, 0);
}

void SdlVideo::copy(SDL_Texture* texture, const SDL_Rect& dest) {
    copy(texture, 0, &dest);
}
void SdlVideo::copy(SDL_Texture* texture, const SDL_Rect* src,
        const SDL_Rect* dest) {
    sdlCall(SDL_RenderCopy(renderer, texture, src, dest));
}

void SdlVideo::drawRect(const SDL_Rect& rect) {
    sdlCall(SDL_RenderDrawRect(renderer, &rect));
}

SdlVideo::~SdlVideo() {
    if(renderer) SDL_DestroyRenderer(renderer);
    if(window)   SDL_DestroyWindow(window);
}

void SdlVideo::clear() {
    sdlCall(SDL_RenderClear(renderer));
}

void SdlVideo::present() {
    SDL_RenderPresent(renderer);
}

void SdlVideo::setDrawColor(int r, int g, int b, int a) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void SdlVideo::sdlCall(int call) {
    // All SDL calls return 0 upon success.
    if(call != 0)
        throw SdlVideoException::sdlGetError();
}

