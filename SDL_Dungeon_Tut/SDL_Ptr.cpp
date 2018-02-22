#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <memory>

struct SDL_Deleter {
	void operator()(SDL_Window *p) const { SDL_DestroyWindow(p); }
	void operator()(SDL_Renderer *p) const { SDL_DestroyRenderer(p); }
	void operator()(SDL_Texture *p) const { SDL_DestroyTexture(p); }
	void operator()(SDL_Surface *p) const { SDL_FreeSurface(p); }
};

template<typename SDLType>
using uptr = std::unique_ptr<SDLType, SDL_Deleter>;
template<typename SDLType>
using sptr = std::shared_ptr<SDLType>;
